#include <Servo.h>
Servo myservo;  // create servo object to control a servo

#define potPin 2 // analog pin
#define irPin 8 // digital input
#define servoPin 5 // PWM pin
#define transistorPin 4 // digital output

int maxTime = 3000; // longest time interval between IR reads (ms)
int minTime = 1350; // shortest time interval between IR reads (ms)
int servoSpeed = 30; // control servo speed
unsigned long time_now = millis();
int potDelay;

void setup() {
  Serial.begin(9600);
  pinMode(irPin, INPUT_PULLUP); // IR sensor input
  pinMode(transistorPin, OUTPUT); // transistor output
  myservo.attach(servoPin);
}

void loop() {
  int potDelay = analogRead(0); // read delay
  potDelay = map(potDelay, 0, 1023, minTime, maxTime) ; // map delay to time scale

  if (potDelay <= minTime + 50) { // do nothing (potentiometer was set off)
    Serial.println("System off");
  }
  else if ((millis() > (time_now + potDelay)) && !digitalRead(irPin)) { // delay satisfied and object present
    time_now = millis(); // only need to use potDelay if device just sprayed
    Serial.println("Object detected");

    digitalWrite(transistorPin, HIGH); // turn on transistor, allow current through servo
    // wiring up the transistor pin makes the motor buzz but not move. Decreasing the base voltage from ~5/3 hasn't helped either
    delay(500); // reach steady state transistor performance

    Serial.println("Transistor on");
    for (int pos = 0; pos <= 180; pos += 10) { //for loop that move the motor from 0 to 180
      myservo.write(pos);
      delay(servoSpeed); // control speed
    }
    delay(100);
    myservo.write(0); // move the motor back to 0 without delay
    delay(500);

    digitalWrite(transistorPin, LOW); // cut off on transistor, block current through servo
  }
}
