void measurement_ino()

{
// Take Measurement    
    take_Measurement(decToChar(Probe_Address), Soil_Mositure_Val, "M!"); delay(30);
    take_Measurement(decToChar(Probe_Address), Salinity_Val, "M2!"); delay(30);
    take_Measurement(decToChar(Probe_Address), Temperature_Val, "M4!");delay(30);
    take_Measurement(decToChar(Probe_Address), Battery_Val, "M9!");delay(30);//???
  /*
    //Store measurement data
    String temperature_5cm, temperature_15cm, temperature_25cm, temperature_35cm, temperature_45cm, temperature_55cm;
    temperature_5cm = Temperature_Val[0];
    temperature_15cm = Temperature_Val[1];
    temperature_25cm = Temperature_Val[2];
    temperature_35cm = Temperature_Val[3];
    temperature_45cm = Temperature_Val[4];
    temperature_55cm = Temperature_Val[5];
    String moist_5cm, moist_15cm, moist_25cm, moist_35cm, moist_45cm, moist_55cm;
    moist_5cm = Soil_Mositure_Val[0];
    moist_15cm = Soil_Mositure_Val[1];
    moist_25cm = Soil_Mositure_Val[2];
    moist_35cm = Soil_Mositure_Val[3];
    moist_45cm = Soil_Mositure_Val[4];
    moist_55cm = Soil_Mositure_Val[5];
    String salinity_5cm, salinity_15cm, salinity_25cm, salinity_35cm, salinity_45cm, salinity_55cm;
    salinity_5cm = Salinity_Val[0];
    salinity_15cm = Salinity_Val[1];
    salinity_25cm = Salinity_Val[2];
    salinity_35cm = Salinity_Val[3];
    salinity_45cm = Salinity_Val[4];
    salinity_55cm = Salinity_Val[5];
    String Battery, Battery1;
    Battery = Battery_Val[0];Battery1 = Battery_Val[1];

    Serial.print("Time:\t");
    Serial.print(millis()/1000);
    Serial.print(":\n");
    //show measurement data
    Serial.print("T_5cm  = ");
    Serial.println(temperature_5cm);
    /*
    Serial.print("T_15cm = ");
    Serial.println(temperature_15cm);
    Serial.print("T_25cm = ");
    Serial.println(temperature_25cm);
    Serial.print("T_35cm = ");
    Serial.println(temperature_35cm);
    Serial.print("T_45cm = ");
    Serial.println(temperature_45cm);
    Serial.print("T_55cm = ");
    Serial.println(temperature_55cm);
    Serial.print("\n");
   
    Serial.print("soi_5cm  = ");
    Serial.println(moist_5cm);
    /*
    Serial.print("soi_15cm = ");
    Serial.println(moist_15cm);
    Serial.print("soi_25cm = ");
    Serial.println(moist_25cm);
    Serial.print("soi_35cm = ");
    Serial.println(moist_35cm);
    Serial.print("soi_45cm = ");
    Serial.println(moist_45cm);
    Serial.print("soi_55cm = ");
    Serial.println(moist_55cm);
    Serial.print("\n");
    
    Serial.print("sal_5cm  = ");
    Serial.println(salinity_5cm);
    /*
    Serial.print("sal_15cm = ");
    Serial.println(salinity_15cm);
    Serial.print("sal_25cm = ");
    Serial.println(salinity_25cm);
    Serial.print("sal_35cm = ");
    Serial.println(salinity_35cm);
    Serial.print("sal_45cm = ");
    Serial.println(salinity_45cm);
    Serial.print("sal_55cm = ");
    Serial.println(salinity_55cm);
    Serial.print("\n");
      
    Serial.print("Battery = ");
    Serial.println(Battery);
    Serial.print("\n");
 */
  
}
