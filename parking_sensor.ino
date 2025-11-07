/*
  Ultrasonic Parking Assistant
  By H. Bahadir Zunluoglu
*/

// sensor pins
const int trigPin = 9;
const int echoPin = 10;

// outputs
const int redLedPin = 3;
const int yellowLedPin = 4;
const int greenLedPin = 5;
const int buzzerPin = 11;

// logic variables
long duration;
int distance;

// setup
void setup() {
  // define pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // define output pins
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // for serial monitor in IDE
  Serial.begin(9600); 
}

// main logic
void loop() {
  // Step 1: get distance

  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Send a pulse 
  // we are using 10 microseconds here
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echo time
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in cm
  // speed of sound in cm * µs / 2 (since its a round trip)
  distance = duration * 0.034 / 2;

  // for debugging
  Serial.print("distance is ");
  Serial.print(distance);

  // Step 2: logic for leds and sound
  
  if (distance > 50) {
    // Safe: green + no sound
    digitalWrite(greenLedPin, HIGH); // green led
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
    digitalWrite(buzzerPin, LOW); 
    
  } else if (distance > 20 && distance <= 50) {
    // warning: yellow + slow beep
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH); // yellow led
    digitalWrite(redLedPin, LOW);
    
    digitalWrite(buzzerPin, HIGH);
    delay(250); // beep for 0.25 seconds
    digitalWrite(buzzerPin, LOW);
    delay(250); // silence for 0.25 seconds
    
  } else if (distance <= 20 && distance > 0) {
    // danger: red + fast beep
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, HIGH); // red led
    
    digitalWrite(buzzerPin, HIGH);
    delay(75); // beep for 0.075 seconds
    digitalWrite(buzzerPin, LOW);
    delay(75); // silence for 0.075 seconds
    
  } else {
    // Error: no led + wait a bit before reading again
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(100); // Wait a bit
  }
}