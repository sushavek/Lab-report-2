/*
  This program is a SD card that can read up to 200 values of temperature and humidity.

MOSI = pin 11;
MISO = pin 12;
CLK = pin 13;
8CS = pin 10;
*/
                          //SD card pins and library codes
#include <SPI.h>
#include <SD.h>
const int chipSelect = 10;
File myFile;
                          //DHT 11 library and pin
#include "DHT.h"
#define DHTTYPE DHT11
int DHTPin = 6;
DHT dht(DHTPin, DHTTYPE);
float Temperature;
float Humidity;

void setup() {
                         // Open serial communications and wait for port to open:
  Serial.begin(9600);
  pinMode(DHTPin, INPUT);
  dht.begin();
  Initialize_SDcard();
 
}

void loop() {
  Write_SDcard();      
  Read_TempHum();
  delay(1000);           // Wait for 1 sec
}
  void Read_TempHum(){   //showing the temperature and humidity in serial monitor   
  Temperature = dht.readTemperature(); 
  Humidity = dht.readHumidity();  
  Serial.println(Temperature);
  Serial.println(Humidity);
}
  void Initialize_SDcard()
{
  if (!SD.begin(chipSelect))
  {
    Serial.println("Card failed, or not present");
    return;
   }
  File dataFile = SD.open("LoggerCD.txt", FILE_WRITE);
  if (dataFile)
  {
    dataFile.println("Temperature,Humidity"); //Write the first row of the excel file
    dataFile.close();
   }
}
void Write_SDcard()
{
  File dataFile = SD.open("LoggerCD.txt", FILE_WRITE);
  if (dataFile)
  {
    dataFile.print(Temperature); //Store date on SD card
    dataFile.print(","); //Move to next column using a ","
    dataFile.print(Humidity); //Store date on SD card
    dataFile.print(","); //Move to next column using a ","
    dataFile.println(); //End of Row move to next row
    dataFile.close(); //Close the file
   }
  else
   Serial.println("SD card writing failed");
}
