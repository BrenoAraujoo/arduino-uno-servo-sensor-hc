#include <Servo.h>

Servo servoMotor;


int trigPin = 7;  // trigger pin D5
int echoPin = 8;  // echo pin

int pos = 0;

double distance = 0;
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  servoMotor.attach(3);
}

void loop() {

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  distance = pulseIn(echoPin, HIGH);

  distance = distance * 340;
  distance = distance / 2;
  distance = distance / 10000;

  Serial.print(distance);
  Serial.println(" cm");


  if (distance <= 10.00 && distance !=0.0) {
    for(pos; pos<=90; pos ++){
      servoMotor.write(pos);

    }

    delay(5000);

      for(pos; pos>=0; pos--){
      servoMotor.write(pos);
      delay(25);
    }
    
  }





  delay(2000);

  servoMotor.write(0);
}
