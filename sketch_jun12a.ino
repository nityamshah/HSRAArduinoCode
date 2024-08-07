const int ledPin = 8;
const int buttonPin = 2;
int buttonState = 0;
int ledState = 0; //0 for LOW, 1 for HIGH

void setup() {
  // put your setup code here, to run once:
  //pinMode(ledPin, OUTPUT); //led
  pinMode(buttonPin, INPUT); //button
  attachInterrupt(digitalPinToInterrupt(2), isr, RISING);
  Serial.begin(9600);
}

void isr(){
  ledState = ledState == 0 ? 1 : 0;
}

void loop(){
  // read the state of the pushbutton value:
  // delay(100);
  buttonState = digitalRead(buttonPin);
  Serial.println(ledState);

  if (ledState == 0){
    digitalWrite(8, LOW);
  }
  if (ledState == 1){
    digitalWrite(8, HIGH);
  }
}



  
   /*
   digitalWrite(8, HIGH);
   delay(100);
   digitalWrite(8, LOW);
   delay(100);
   */


