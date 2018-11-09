//int threshold = ;
int driveSpeed = 255;
int motorL = 5;
int motorLspeed = 4;
int motorR = 3;
int motorRspeed = 2;
int delayTime = 3000;
int mode = 7;

void setup() {
  
  pinMode (motorLspeed, OUTPUT);
  pinMode (motorL, OUTPUT);
  pinMode (motorRspeed, OUTPUT);
  pinMode (motorR, OUTPUT);
  pinMode(mode, OUTPUT);

}
void stopRobot() {
  
  digitalWrite(motorR, HIGH);
  analogWrite(motorRspeed, 0);
  digitalWrite(motorL, HIGH);
  analogWrite(motorLspeed, 0);
  
}
void drive() {
  
  digitalWrite(motorR, HIGH);
  analogWrite(motorRspeed, driveSpeed);
  digitalWrite(motorL, HIGH);
  analogWrite(motorLspeed, driveSpeed);
  delay(delayTime);
  stopRobot();

}

void turnLeft() {

  digitalWrite(motorR, HIGH);
  analogWrite(motorRspeed, driveSpeed);
  digitalWrite(motorL, LOW);
  analogWrite(motorLspeed, driveSpeed);
  delay(delayTime);
  stopRobot();
  
}

void turnRight () {
  
  digitalWrite(motorR, LOW);
  analogWrite(motorRspeed, driveSpeed);
  digitalWrite(motorL, HIGH);
  analogWrite(motorLspeed, driveSpeed);
  delay(delayTime);
  stopRobot();
  
}
void loop() {
  
  /*if(getUSF() == threshold) {
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
*/
digitalWrite(mode, HIGH);
turnLeft();
turnRight();

}
