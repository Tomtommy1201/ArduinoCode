
void sdi_config()
{

  while(!Serial);
#ifdef USART_DEBUG
  Serial.println("Opening SDI-12 bus...");
#endif
  mySDI12.begin();
  delay(500); // allow things to settle

  // Power the sensors;
  if(POWER_PIN > 0){
#ifdef USART_DEBUG
    Serial.println("Powering up sensors...");
#endif
    pinMode(POWER_PIN, OUTPUT);
    digitalWrite(POWER_PIN, HIGH);
    delay(200);
  }

#ifdef USART_DEBUG
  Serial.println("Scanning... please wait...");
#endif
  /*
      Quickly Scan the Address Space
   */
  boolean found = false;
  for(byte i = 0; i <= 9; i++) if(checkActive(i)) { Probe_Address = i; found = true; break;}   // scan address space 0-9
   /*YOU CAN WRITE EXPLANATION HERE IF YOU WANT
      See if there are any active sensors.
   */
#ifdef USART_DEBUG
  Serial.print("Probe address found:  ");
//  Serial.println(decToChar(Probe_Address));
  Serial.println(Probe_Address);
  Serial.print("This probe have six sensors:  ");
#endif

  if(!found) {
#ifdef USART_DEBUG
    Serial.println("No sensor, please check connections and restart.");
#endif
    while(true);
  } // stop here

#ifdef USART_DEBUG
  Serial.println();
  Serial.println("Measurement Data...");
#endif
}
