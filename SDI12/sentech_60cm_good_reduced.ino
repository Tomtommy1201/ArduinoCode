
//#define USART_DEBUG
//SDI---------------------------------------------------------------------
#include <SDI12.h>
#define SERIAL_BAUD 115200  // The baud rate for the output serial port
#define DATA_PIN 7         // The pin of the SDI-12 data bus
#define POWER_PIN 8       // The SDI-12 POWER PIN
#define GPRS_Rx 11
#define GPRS_Tx 10
SDI12 mySDI12(DATA_PIN);
String Soil_Mositure_Val[6], Salinity_Val[6], Temperature_Val[6], Battery_Val[6];
//------------------------------------------------------------------------
//SIM800L----------------------------------------

#include "Adafruit_FONA.h"
#define FONA_RST 12
SoftwareSerial sim800ss(10, 11);
Adafruit_FONA mySim800 = Adafruit_FONA(FONA_RST);
char url_string[] = "api.thingspeak.com/update?api_key=";
char APIKey1_string[] = "AQXLXIOOPG3LTRV8";
char APIKey2_string[] = "KI2OKX1JMH4FECLC";
char APIKey3_string[] = "CUTRXLCADM9BJKF7";
char field1_string[] = "&field1";
char field2_string[] = "&field2";
char field3_string[] = "&field3";
char field4_string[] = "&field4";
char field5_string[] = "&field5";
char field6_string[] = "&field6";
char field7_string[] = "&field7";

int net_status;
boolean gprs_on = false;
boolean tcp_on = false;
char http_cmd[150];
String response = "";
uint16_t statuscode;
int16_t length;

//--------------------------------------------------------------

char decToChar(byte i){
  if(i <= 9) return i + '0';
  else return i;
}
void printBufferToScreen(String *measurement, int i){
  String buffer = "", element = "";
  mySDI12.read(); // consume address
  while(mySDI12.available()){
    char c = mySDI12.read();
    if((c == '+') || (c == '-')){    
        buffer += ',';
        if(element != ""){measurement[i] = element;  element = ""; i++;}
    }
    else if ((c != '\n') && (c != '\r')) {
      buffer += c; element += c; 
    }
    measurement[i] = element;     
    delay(20);
  }
}
void take_Measurement(char i, String *MeasureData, String Cmd){
  String command = "";
  command += i;
  command += Cmd; // SDI-12 measurement command format  [address]['M'][!]
  mySDI12.sendCommand(command);
  delay(60);

  // wait for acknowlegement with format [address][ttt (3 char, seconds)][number of measurments available, 0-9]
  String sdiResponse = "";
  while (mySDI12.available())  // build response string
  {
    char c = mySDI12.read();
    if ((c != '\n') && (c != '\r'))
    {
      sdiResponse += c;
      delay(5);
    }
  }
  mySDI12.clearBuffer();

  // find out how long we have to wait (in seconds).
  uint8_t wait = 0;
  wait = sdiResponse.substring(1,4).toInt();

  // Set up the number of results to expect
  // int numMeasurements =  sdiResponse.substring(4,5).toInt();

  unsigned long timerStart = millis();
  while((millis() - timerStart) < (1000 * wait)){
    if(mySDI12.available())  // sensor can interrupt us to let us know it is done early
    {
      mySDI12.clearBuffer();
      break;
    }
  }
  // Wait for anything else and clear it out
  mySDI12.clearBuffer();

  // in this example we will only take the 'DO' measurement
  command = "";
  command += i;
  command += "D0!"; // SDI-12 command to get data [address][D][dataOption][!]
  mySDI12.sendCommand(command);
  while(!(mySDI12.available()>1)){}  // wait for acknowlegement
  delay(20); // let the data transfer
  printBufferToScreen(MeasureData, 0);
  mySDI12.clearBuffer();
  
  command = "";
  command += i;
  command += "D1!"; // SDI-12 command to get data [address][D][dataOption][!]
  mySDI12.sendCommand(command);
  while(!(mySDI12.available()>1)){}  // wait for acknowlegement
  delay(20); // let the data transfer
  printBufferToScreen(MeasureData, 3);
  mySDI12.clearBuffer();
}
boolean checkActive(int i){

  String myCommand = "";
  myCommand = "";
  myCommand += decToChar(i);                 // sends basic 'acknowledge' command [address][!]
  myCommand += "!";

  for(int j = 0; j < 3; j++){            // goes through three rapid contact attempts
    mySDI12.sendCommand(myCommand);
    delay(20);
    if(mySDI12.available()) {  // If we here anything, assume we have an active sensor
      mySDI12.clearBuffer();
      return true;
    }
  }
  mySDI12.clearBuffer();
  return false;
}
int Probe_Address;

void setup(){
    
  Sim800L_Config();
  sdi_config();
}

void loop(){
  measurement_ino();
   delay(60000);
   GPRS_Trans();
  delay(10000);
}
