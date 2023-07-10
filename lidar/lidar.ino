#include <RPLidar.h>
#include <SoftwareSerial.h>
// This is in COM5
// Define the software serial port

// You need to create an RPLidar driver instance 
RPLidar lidar;
SoftwareSerial mySerial(10, 11); // RX | TX
#define RPLIDAR_MOTOR 3 // The PWM pin for control the speed of RPLIDAR's motor.
                        // This pin should connected with the RPLIDAR's MOTOCTRL signal 
                       
                        
void setup() {
  // set pin modes
  pinMode(RPLIDAR_MOTOR, OUTPUT);
  pinMode(7, OUTPUT);

  // start the serial communication with the computer
  Serial.begin(115200);
  
  // initialize the RPLidar driver
  mySerial.begin(115200);
  lidar.begin(Serial);
}

void loop() {
  if (IS_OK(lidar.waitPoint())) {
    float distance = lidar.getCurrentPoint().distance; //distance value in mm unit
    float angle    = lidar.getCurrentPoint().angle; //anglue value in degree
    bool  startBit = lidar.getCurrentPoint().startBit; //whether this point is belong to a new scan
    byte  quality  = lidar.getCurrentPoint().quality; //quality of the current measurement
    
    // Send Lidar data to the computer via the software serial port
    mySerial.print(distance);
    mySerial.print(",");
    mySerial.print(angle);
    mySerial.print(",");
    mySerial.print(startBit);
    mySerial.print(",");
    mySerial.println(quality);
    
    digitalWrite(7, true);
    
  } 
  else {
    lidar.startScan();
    analogWrite(RPLIDAR_MOTOR, 255);
    digitalWrite(7, false);
    delay(1000);    
  }
}
