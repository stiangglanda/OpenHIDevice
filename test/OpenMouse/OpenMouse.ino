#include <PS2MouseHandler.h>

#include <SoftwareSerial.h>

// Pin Definitions
const int DATA_PIN = 2;
const int CLK_PIN = 3;
const int LED_PIN = 4;
const int LED2_PIN = 5;

// Variables to store movement
volatile int8_t x_movement = 0;
volatile int8_t y_movement = 0;

// Interrupt flags
volatile bool data_ready = false;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set up pins
  pinMode(DATA_PIN, INPUT);
  pinMode(CLK_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  digitalWrite(LED_PIN, HIGH);
  digitalWrite(LED2_PIN, HIGH);
  
  // Attach interrupts
  attachInterrupt(digitalPinToInterrupt(CLK_PIN), readMouseData, FALLING);
  
  Serial.println("PAW3552DB Mouse Sensor Reader");
}

void loop() {
  // Check if data is ready to be processed
  if (data_ready) {
    // Print movement data
    Serial.print("X Movement: ");
    Serial.print(x_movement);
    Serial.print("\tY Movement: ");
    Serial.println(y_movement);
    
    // Reset movement and flag
    x_movement = 0;
    y_movement = 0;
    data_ready = false;
  }
}

void readMouseData() {
  // Read X movement (assuming active low signaling)
  x_movement = digitalRead(DATA_PIN) ? -1 : 1;
  
  // Read Y movement
  // Note: This is a simplified implementation and may need 
  // adjustment based on exact sensor protocol
  delayMicroseconds(10);  // Small delay to stabilize reading
  y_movement = digitalRead(DATA_PIN) ? -1 : 1;
  
  // Set data ready flag
  data_ready = true;
}

