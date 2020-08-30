///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////RTC CODE BY RABIEE AHMAD//////////////////////////////////////////////////////////////

//Code by Rabiee Ahmad////////////////////////////////////
//Coded by the library of Eric Ayars
//www.github/rabieeahmad
//www.github/tfg13

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <DS3231.h>
#include <Wire.h>

DS3231 Clock;
bool Century=false;
bool h12;
bool PM=true;
byte ADay, AHour, AMinute, ASecond, ABits;
bool ADy, A12h, Apm;

void setup() {
  // Start the I2C interface
  Wire.begin();
  // Start the serial interface
  Serial.begin(9600);
 Clock.setClockMode(true);   //////////////////////// true =  For 12 Hour Mode ///////// false =  For 24 Hour Mode /////////////////////

/*
    Clock.setYear(20);       //////////////////Uncomment this if you want to set the date and time///////////////////////////////////
    Clock.setMonth(8);
    Clock.setDate(28);       
//    Clock.setDoW(Friday);
    Clock.setHour(17);        /////////////////The hour must be set in 24h format even if you want 12h format///////////////////////////
    Clock.setMinute(9);
    Clock.setSecond(0);
 */
}

void loop() {
 

  Serial.print(Clock.getYear(), DEC);
  Serial.print('/');
  // then the month
  Serial.print(Clock.getMonth(Century), DEC);
  Serial.print('/');
  // then the date
  Serial.print(Clock.getDate(), DEC);
  
  Serial.print("    ");
  
 
  Serial.print(Clock.getHour(h12, PM), DEC);
  Serial.print(':');
  Serial.print(Clock.getMinute(), DEC);
  Serial.print(':');
  Serial.print(Clock.getSecond(), DEC);
  // Add AM/PM indicator
  if (h12) {
    if (PM) {
      Serial.println(" PM ");
    } else {
      Serial.println(" AM ");
    }
  } else {
    Serial.println(" 24h ");
  }
  
  delay(1000);
}
