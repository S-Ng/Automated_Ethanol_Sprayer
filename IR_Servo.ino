#include <Servo.h>
Servo myservo;  // create servo object to control a servo
int pos = 0;	// variable to store the servo position

void setup() {
  Serial.begin(9600);
  pinMode('D8', INPUT); // set pin as input
  myservo.attach('D4');
}
void loop() {
  int detect = digitalRead(8); // read obstacle status and store it into "detect"
  if(detect == LOW){ // object present
	for (pos = 0; pos <= 180; pos += 10) {
	myservo.write(pos);
	delay(15);
	}
	for (pos = 180; pos >= 0; pos -= 10) {
	myservo.write(pos);
	delay(15);
	}
  }
  else{
   Serial.println("All clear");  // do nothing
  }
  delay(3000); // wait 3 seconds
}
