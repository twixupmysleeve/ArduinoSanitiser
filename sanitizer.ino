#include <Servo.h>

Servo myservo1;
Servo myservo2;

const int trig = 3;
const int echo = 2;

long duration;
int distance;

void setup() {
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  Serial.begin(9600);
  
  myservo1.attach(9);
  myservo1.write(10);

  myservo2.attach(10);
  myservo2.write(10);
  
  delay(1000);
}

void loop() {
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration*0.034/2;

  Serial.print("Distance: ");
  Serial.println(distance);

  delay(250);

  if (distance<30) {
    push();
  }
}

void push() {
  
  myservo1.write(150);
  myservo2.write(150);
  delay(1000);

  myservo1.write(10);
  myservo2.write(10);
  delay(2200);
}
