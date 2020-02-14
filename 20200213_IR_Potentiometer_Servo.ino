#include <Servo.h>
Servo myservo;  // create servo object to control a servo
int pos;  // variable to store the servo position
int potPin = 2; // potentiometer hooked to analog 2
int maxTime = 5000; // longest time interval between IR reads (ms)
int servoSpeed = 15; // control servo speed
unsigned long time_now = 0;
int potDelay = 0;

void setup() {
  Serial.begin(9600);
  pinMode('8', INPUT); // set pin as input
  myservo.attach(4);
}

void loop() {
  time_now = millis();
  int potDelay = analogRead(potPin); // get delay
  potDelay = map(potDelay, 0, 1023, 0, maxTime); // map potentiometer to time scale

  if (potDelay <= 100){
    Serial.println("This would turn off entire system");
  }
  
  else {
 
  int detect = digitalRead(8); // read obstacle status and store it into "detect"
  if(detect == LOW){ // object present
   Serial.println("Object detected");
  
   for (pos = 0; pos <= 180; pos += 10) { //for loop that move the motor from 0 to 180
     myservo.write(pos);
     delay(servoSpeed);
     Serial.println("Moving +");

   }
   delay(1000); 
   for (pos = 180; pos >= 0; pos -= 10) { //for loop that move the motor back to 0
     myservo.write(pos);
     delay(servoSpeed);
     Serial.println("Moving -");

   } 
  } 
  else{
    Serial.println("No object detected");  // do nothing
  }
 // while(millis() < time_now + potDelay){} // delay [potDelay] ms. Use to adjust delay between IR reads
    //delay(potDelay);
    Serial.println(potDelay);
  }
  
}
