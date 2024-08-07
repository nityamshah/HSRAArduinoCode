#include <Servo.h> 
// Create a servo object 
Servo Servo1;
Servo Servo2;
int pos = 0;  //initial position of the servo

const int servo1Pin = 8;
const int servo2Pin = 7;
const int buttonPin = 2;
int buttonState = 0;
int motorSpin = 0; //0 for OFF, 1 for ON

void setup() {
  //pinMode(ledPin, OUTPUT); //led
  Servo1.attach(servo1Pin); 
  Servo2.attach(servo2Pin);
  pinMode(buttonPin, INPUT); //button
  attachInterrupt(digitalPinToInterrupt(2), isr, RISING);
  Serial.begin(9600);
}

void spinMotor(){
  //while (true){
  for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Servo1.write(pos); // tell servo to go to position in variable 'pos'
    delay(30);                       // controls speed
  }
  for (int pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    Servo1.write(pos); // tell servo to go to position in variable 'pos'
    delay(30);                       // controls speed
  }
   for (int pos = 180; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Servo2.write(pos); // tell servo to go to position in variable 'pos'
    delay(30);                       // controls speed
  }
  for (int pos = 0; pos <= 180; pos += 1) { // goes from 180 degrees to 0 degrees
    Servo2.write(pos); // tell servo to go to position in variable 'pos'
    delay(30);                       // controls speed
  }
  //}
}

void isr(){
  motorSpin = 1;
}

void loop(){

  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);

  if (motorSpin){
    noInterrupts();
    spinMotor();
    motorSpin = 0;
    interrupts();
  }
}


