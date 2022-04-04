/*
    This program is a DHT11 sensor to have the temperature and the humidity 
    that we can see in a LCD and also in a serial monitor.
 
 */
#include "DHT.h"                        // Add the DHT11 library
#define DHTPIN 4                        // Pin 4 to use fot the data
#define DHTTYPE DHT11                   // DHT 11

DHT dht(DHTPIN, DHTTYPE);               // Pin 4 and type 11

                                        //LCD Display

#include <LiquidCrystal.h>              //include the LiquidCrystal library code

const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;      //the pins are constant and always to use
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int switchPin = 2;                 // set up a constant for the tilt switchPin
static int hits = 0;                           
int switchState = 0;                    // variable to hold the value of the switchPin
int prevSwitchState = 0;                // variable to hold previous value of the switchpin
int pushbutton;                          
                                        // void setup

void setup() {
  Serial.begin(9600);                   // Serial Communication
  Serial.println(F("DHTxx test!"));     // To know that you're doing a sensor test
  dht.begin();                          // It will begin to sense the temperature and humidity
  lcd.clear();
  lcd.begin(0,0);                      // the distance from the lcd display     
  lcd.print("Temperature");             //LCD DISPLAY temperature
  lcd.begin(0,0);                       // the distance from the lcd display       
  lcd.print("Humidity");                //LCD DISPLAY humidity

  pinMode(switchPin,INPUT);             // set up the switch pin as an input
}
                                        // void loop
void loop() {
                    
  delay(500);                           // Wait a few seconds between measurements.
  float h = dht.readHumidity();                    
  float t = dht.readTemperature();      // Read temperature as Celsius (the default)   
  float f = dht.readTemperature(true);  // Read temperature as Fahrenheit (isFahrenheit = true)

                                       
  if (isnan(h) || isnan(t) || isnan(f)) {   // Check if any reads failed and exit early (to try again).
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

                                          
  float hif = dht.computeHeatIndex(f, h);                  // Compute heat index in Fahrenheit (the default)
  
  float hic = dht.computeHeatIndex(t, h, false);           // Compute heat index in Celsius (isFahreheit = false)
                                      //LCD LOOP
                                      //change screen                                     
 pushbutton= digitalRead(13);
 if(pushbutton==1)                    //screen 2 when the push button is pressed
 {
  Serial.println("Humidity");
  lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Humidity");
 } else
 if (pushbutton==0)                  // screen 1 when the push button is not pressed
 {
  Serial.println("Temperature");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperature");
 }
}
