#include <dummy.h>
#include <ESP8266WiFi.h>


#define TRIG_PIN 8
#define ECHO_PIN 7
#define TIME_OUT 2000

float getDistance() {
  long duration, distanceCm;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, TIME_OUT);

  // convert to distance
  distanceCm = duration / 29.1 / 2;

  return distanceCm;
}

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  long distance = getDistance();

  if (distance <= 0) {
    Serial.println("Echo time out !!");
  } else {
    Serial.print("Distance to nearest obstacle (cm): ");
    Serial.println(distance);
  }
  delay(600);
}
