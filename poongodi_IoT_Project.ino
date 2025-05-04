#include <LiquidCrystal.h>

// Initialize the LCD with the appropriate pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Define pins for MQ3 sensor and other components
const int MQ3Pin = A0;  // MQ3 sensor's analog output connected to A0
const int buzzerPin = 9; // Buzzer connected to pin 9
const int motorPin = 10; // DC Motor connected to pin 10

void setup() {
  pinMode(MQ3Pin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  lcd.begin(16, 2); // Set up the LCD's number of columns and rows
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int sensorValue = 400;//analogRead(MQ3Pin); // Read the analog value from sensor
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Alcohol Level:");
  lcd.setCursor(0, 1);
  lcd.print(sensorValue);
  Serial.print("Alcohol Level: ");
  Serial.println(sensorValue); // Print the sensor value to serial monitor

  if (sensorValue > 300) {  // Threshold value for alcohol detectio    digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
    digitalWrite(motorPin, LOW);  // Lock the engine
    digitalWrite(buzzerPin, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Engine Locked");
    lcd.setCursor(0, 1);
    lcd.print("Drive Safely!");
    Serial.println("Engine Locked. Drive Safely!");
  } else {
    digitalWrite(buzzerPin, LOW); // Turn off the buzzer
    digitalWrite(motorPin, HIGH); // Allow the engine to start
  }

  delay(1000); // Delay for a bit before reading again
}