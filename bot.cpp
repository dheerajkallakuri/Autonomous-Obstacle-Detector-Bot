#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 11;
const int motorLeftForward = 5;
const int motorLeftBackward = 6;
const int motorRightForward = 3;
const int motorRightBackward = 4;

Servo myservo;
long duration;
int distance;
int tolerance = 15;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorLeftForward, OUTPUT);
  pinMode(motorLeftBackward, OUTPUT);
  pinMode(motorRightForward, OUTPUT);
  pinMode(motorRightBackward, OUTPUT);
  myservo.attach(servoPin);
  myservo.write(90); // Center position
  Serial.begin(9600);
}

void loop() {
  distance = getDistance();
  if (distance < tolerance) {
    stopRobot();
    int leftDistance = checkSide(0); // Check left
    int rightDistance = checkSide(180); // Check right
    if (leftDistance > tolerance && leftDistance > rightDistance) {
      turnLeft();
    } else if (rightDistance > tolerance && rightDistance > leftDistance) {
      turnRight();
    } else {
      // No clear path, turn back
      turnBack();
    }
  } else {
    moveForward();
  }
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}

int checkSide(int angle) {
  myservo.write(angle);
  delay(500); // Wait for the servo to reach the position
  int sideDistance = getDistance();
  myservo.write(90); // Return to center position
  return sideDistance;
}

void moveForward() {
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorRightForward, HIGH);
}

void stopRobot() {
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorRightForward, LOW);
}

void turnLeft() {
  digitalWrite(motorLeftBackward, HIGH);
  digitalWrite(motorRightForward, HIGH);
  delay(500); // Adjust based on your robot's turning speed
  stopRobot();
}

void turnRight() {
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorRightBackward, HIGH);
  delay(500); // Adjust based on your robot's turning speed
  stopRobot();
}

void turnBack() {
  digitalWrite(motorLeftBackward, HIGH);
  digitalWrite(motorRightForward, HIGH);
  delay(1000); // Adjust based on your robot's turning speed
  stopRobot();
}
