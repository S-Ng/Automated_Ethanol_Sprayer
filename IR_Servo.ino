#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8, INPUT); // set pin as input
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  int detect = digitalRead(8); // read obstacle status and store it 
     into "detect"
  if(detect == LOW){ // object present
    for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(15);
    }
    for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15);
    }
  }
  else{
   Serial.println("All clear");  // do nothing
  }
  delay(3000); // wait 3 seconds
}
