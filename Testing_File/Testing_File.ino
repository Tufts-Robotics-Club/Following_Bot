//int threshold = ;
int driveSpeed = 255;
int motorL = 5;
int motorLspeed = 4;
int motorR = 3;
int motorRspeed = 2;
int delayTime = 3000;
int mode = 7;
int x =1;

void drive() {
  //turn right motor forward
  digitalWrite(motorR, HIGH);
  analogWrite(motorRspeed, driveSpeed);
  //turn left motor forward
  digitalWrite(motorL, HIGH);
  analogWrite(motorLspeed, driveSpeed);

}
void stopRobot(){
  //Stop the right motor 
  digitalWrite(motorR, HIGH);
  analogWrite(motorRspeed, 0);
  //stop the left motor
  digitalWrite(motorL, HIGH);
  analogWrite(motorLspeed, 0);
}
void setup() {
  
  pinMode (motorLspeed, OUTPUT);
  pinMode (motorL, OUTPUT);
  pinMode (motorRspeed, OUTPUT);
  pinMode (motorR, OUTPUT);
  pinMode(mode, OUTPUT);
  digitalWrite(mode, HIGH);
}
void loop() {
  if(x == 1){
    drive();
    delay(delayTime);
    x++;
  }
  stopRobot();
  
}
