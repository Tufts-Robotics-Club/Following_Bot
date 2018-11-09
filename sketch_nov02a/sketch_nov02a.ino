/*
 * created by Rui Santos, https://randomnerdtutorials.com
 * 
 * Complete Guide for Ultrasonic Sensor HC-SR04
 *
    Ultrasonic sensor Pins:
        VCC: +5VDC
        Trig : Trigger (INPUT) - Pin11
        Echo: Echo (OUTPUT) - Pin 12
        GND: GND
 */

// sets pins of analog and digital output for the motors
int motorL = ; //direction pin for left motor
int motorLspeed = ; //speed pin for left motor
int motorRspeed = ; //speed pin for right motor
int motorR = ; //direction pin for right motor
int motorTime = ; time in millisecond that it takes to make a turn 
int driveSpeed =255 ; //speed that the motors turn at 

//ultrasonic global variables
int USFOn = ;    // Trigger for fron Ultrasonic Sensor
int USFEcho = ;    // Echo for front Ultrasonic Sensor
int USROn = ; // Trigger for fron Ultrasonic Sensor
int USREcho = ; //Echo for front Ultrasonic Sensor
double threshold = ; //distance in cm that trigger sensor
long duration, cm;

double getUSF() {
    // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    digitalWrite(USFOn, LOW);
    delayMicroseconds(5);
    digitalWrite(USFOn, HIGH);
    delayMicroseconds(10);
    digitalWrite(USFOn, LOW);
   
    // Read the signal from the sensor: a HIGH pulse whose
    // duration is the time (in microseconds) from the sending
    // of the ping to the reception of its echo off of an object.
    pinMode(USFEcho, INPUT);
    duration = pulseIn(USFEcho, HIGH);
   
    // Convert the time into a distance
    double cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343 
    return cm;
  }
  
 double getUSR() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(USROn, LOW);
  delayMicroseconds(5);
  digitalWrite(USROn, HIGH);
  delayMicroseconds(10);
  digitalWrite(USROn, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(USREcho, INPUT);
  duration = pulseIn(USREcho, HIGH);
 
  // Convert the time into a distance
  double cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
    
  return cm;
}
  void drive() {
  //turn right motor forward
  digitalWrite(motorR, HIGH);
  analogWrite(motorRspeed, driveSpeed);
  //turn left motor forward
  digitalWrite(motorL, HIGH);
  analogWrite(motorLspeed, driveSpeed);

}

void turnLeft() {
  //turn right motor forward
  digitalWrite(motorR, HIGH);
  analogWrite(motorRspeed, driveSpeed);

  //turn left motor backward
  digitalWrite(motorL, LOW);
  analogWrite(motorLspeed, driveSpeed);
  delay(delayTime);
  
}

void turnRight () {
  //Turn right motor backwards
  digitalWrite(motorR, LOW);
  analogWrite(motorRspeed, driveSpeed);

  //Turn Left motor forward
  digitalWrite(motorL, HIGH);
  analogWrite(motorLspeed, driveSpeed);
  delay(delayTime);
}
  
void setup() 
{
 //Tell the computer to communicate with arduino 
  Serial.begin (9600);

  //Right Motor Setup
  pinMode(motorR, OUTPUT);
  pinMode(motorRspeed, OUTPUT);

  //Left Motor Setup
  pinMode(motorL, OUTPUT);
  pinMode(motorLspeed, OUTPUT);

  //Set up front ultrasonic sensor
  pinMode(USFOn, OUTPUT);
  pinMode(USFEcho, INPUT);

  //Set up right ultrasonic sensor
  pinMode(USROn, OUTPUT);
  pinMode(USREcho, INPUT);

}

void loop() {
  if(getUSF() == threshold) {
    if(getUSF() == threshold) {
      turnLeft();
    }
    else {
      turnRight();
    }
  }
  else if(getUSR != threshold) {
    turnRight();
  }
  else {
    drive();
  }
delay(10000) // give the robot a break
