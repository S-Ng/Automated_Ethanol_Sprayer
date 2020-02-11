#include <Servo.h>
Servo myservo;  // create servo object to control a servo
int pos;  // variable to store the servo position

void setup() {
  Serial.begin(9600);
  pinMode('8', INPUT); // set pin as input
  myservo.attach(4);
  
}
void loop() {
  int detect = digitalRead(8); // read obstacle status and store it into "detect"
  if(detect == LOW){ // object present
    Serial.println("yo");
    pos = 0;
    myservo.write(180);
    delay(1000);
    myservo.write(70);
//    for (pos = 0; pos <= 180; pos += 10) {
//      Serial.println(pos);
//      myservo.write(pos);
//      delay(15);
//    }
//    for (pos = 180; pos >= 0; pos -= 10) {
//      myservo.write(pos);
//      delay(15);
//    }
  }
  else{
   pos = 180;
   Serial.println("All clear");  // do nothing
  }
  delay(500); // wait 0.5 seconds
}
