#include "TinyGPS++.h"
#include "SoftwareSerial.h"
SoftwareSerial serial_connection(10, 11); //RX=pin 10 green, TX=pin 11 yellow
TinyGPSPlus gps;//This is the GPS object that will pretty much do all the grunt work with the NMEA data

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//This opens up communications to the Serial monitor in the Arduino IDE
  serial_connection.begin(9600);//This opens up communications to the GPS
  Serial.println("GPS Start");//Just show to the monitor that the sketch has started
}

void loop() {
  // put your main code here, to run repeatedly:
  while (serial_connection.available()) //While there are characters to come from the GPS
  {
    gps.encode(serial_connection.read());//This feeds the serial NMEA data into the library one char at a time
    if (gps.location.isUpdated()){
    double lat = gps.location.lat(); //This will pretty much be fired all the time anyway but will at least reduce it to only after a package of NMEA data comes in
    double lng = gps.location.lng();
    //Serial.println("Satellite Count:");
    Serial.println(gps.satellites.value());
    Serial.println(",");
    Serial.println(lat);
    Serial.println(",");
    Serial.println(lng);
    }
  }
}
