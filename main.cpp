#include <Arduino.h>


const int trigPin = 5;  // Define the trigger pin
const int echoPin = 18; // Define the echo pin

void setup() {
   Serial.begin(115200);      // Initialize serial communication at 9600 baud
  pinMode(trigPin, OUTPUT); // Set the trigger pin as an output
  pinMode(echoPin, INPUT);  // Set the echo pin as an input
}



void loop() {
  // Send a 10us pulse to the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the pulse on the echo pin
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance (speed of sound is ~343 m/s)
  float distance = (duration * 0.0343) / 2;

  // Send the distance to the serial port

  Serial.println(distance);
  
  delay(100); // Adjust delay as needed
}



