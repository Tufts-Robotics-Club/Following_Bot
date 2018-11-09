void drive() {
  //turn right motor forward
  digitalWrite(motorR, HIGH);
  analogWrite(motorRspeed, driveSpeed);
  //turn left motor forward
  digitalWrite(motorL, HIGH);
  analogWrite(motorLspeed, driveSpeed);

}
void setup() {
  //Right Motor Setup
  pinMode(motorR, OUTPUT);
  pinMode(motorRspeed, OUTPUT);

  //Left Motor Setup
  pinMode(motorL, OUTPUT);
  pinMode(motorLspeed, OUTPUT);
}

void loop() {
  drive()
  delay(1111)
}
