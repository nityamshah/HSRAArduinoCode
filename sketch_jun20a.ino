#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 3; 
// Create a servo object 
Servo Servo1;
int pos = 0;  //initial position of the servo

void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin); 
}

/*INPUT_PULLUP send to arduino LOW signal, so, when you press  the button, you send a LOW signal to arduino*/

void loop(){ 
  for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // controls speed
  }
  for (int pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    Servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // controls speed
  }
}