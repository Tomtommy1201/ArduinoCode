void GPRS_Trans() {
    char tmp1[5],tmp2[5],tmp3[5],tmp4[5],tmp5[5],tmp6[5],tmp7[5];
    Temperature_Val[0].toCharArray(tmp1,5);
    Temperature_Val[1].toCharArray(tmp2,5);
    Temperature_Val[2].toCharArray(tmp3,5);
    Temperature_Val[3].toCharArray(tmp4,5);
    Temperature_Val[4].toCharArray(tmp5,5);
    Temperature_Val[5].toCharArray(tmp6,5);
 //   Salinity_Val[0].toCharArray(tmp3,5);
    sprintf(http_cmd,"%s%s%s=%s%s=%s%s=%s%s=%s%s=%s%s=%s",url_string,APIKey1_string,field1_string,tmp1,field2_string,tmp2,field3_string,tmp3,
    field4_string,tmp4,field5_string,tmp5,field6_string,tmp6);
    delay(2000);
    while(!tcp_on){
      if (!mySim800.HTTP_GET_start(http_cmd, &statuscode, (uint16_t *)&length)) {
           Serial.println("Failed!");
           Serial.println("Trying again...");
           tcp_on = false;
      }else{
        tcp_on = true; 
        while (length > 0) {
           while (mySim800.available()) {
             char c = mySim800.read();
             response += c;
             length--;
           }
        }
        }
    }
        Serial.println(response);
        if(statuscode == 200){
          Serial.println("Success!");
          tcp_on = false;
      delay(2000);
    }
  
    Soil_Mositure_Val[0].toCharArray(tmp1,5);
    Soil_Mositure_Val[1].toCharArray(tmp2,5);
    Soil_Mositure_Val[2].toCharArray(tmp3,5);
    Soil_Mositure_Val[3].toCharArray(tmp4,5);
    Soil_Mositure_Val[4].toCharArray(tmp5,5);
    Soil_Mositure_Val[5].toCharArray(tmp6,5);
   
    sprintf(http_cmd,"%s%s%s=%s%s=%s%s=%s%s=%s%s=%s%s=%s",url_string,APIKey2_string,field1_string,tmp1,field2_string,tmp2,field3_string,tmp3,
    field4_string,tmp4,field5_string,tmp5,field6_string,tmp6);
    delay(2000);
    while(!tcp_on){
      if (!mySim800.HTTP_GET_start(http_cmd, &statuscode, (uint16_t *)&length)) {
           Serial.println("Failed!");
           Serial.println("Trying again...");
           tcp_on = false;
      }else{
        tcp_on = true; 
        while (length > 0) {
           while (mySim800.available()) {
             char c = mySim800.read();
             response += c;
             length--;
           }
        }
        }
    }
        Serial.println(response);
        if(statuscode == 200){
          Serial.println("Success!");
          tcp_on = false;
      delay(2000);
    }
    
    Salinity_Val[0].toCharArray(tmp1,5);
    Salinity_Val[1].toCharArray(tmp2,5);
    Salinity_Val[2].toCharArray(tmp3,5);
    Salinity_Val[3].toCharArray(tmp4,5);
    Salinity_Val[4].toCharArray(tmp5,5);
    Salinity_Val[5].toCharArray(tmp6,5);
    Battery_Val[0].toCharArray(tmp7,5);
    
   
    sprintf(http_cmd,"%s%s%s=%s%s=%s%s=%s%s=%s%s=%s%s=%s%s=%s",url_string,APIKey3_string,field1_string,tmp1,field2_string,tmp2,field3_string,tmp3,
    field4_string,tmp4,field5_string,tmp5,field6_string,tmp6,field7_string,tmp7);
    delay(2000);
    while(!tcp_on){
      if (!mySim800.HTTP_GET_start(http_cmd, &statuscode, (uint16_t *)&length)) {
           Serial.println("Failed!");
           Serial.println("Trying again...");
           tcp_on = false;
      }else{
        tcp_on = true; 
        while (length > 0) {
           while (mySim800.available()) {
             char c = mySim800.read();
             response += c;
             length--;
           }
        }
        }
    }
        Serial.println(response);
        if(statuscode == 200){
          Serial.println("Success!");
          tcp_on = false;
      delay(2000);
    }


   
}
