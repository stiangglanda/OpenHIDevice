#include <BleMouse.h>
#include <Arduino.h>

#define VRX_PIN  32 // pin connected to VRX pin
#define VRY_PIN  33 // pin connected to VRY pin
#define SW_PIN   17 // ESP32 pin GPIO17 connected to SW  pin

#define LEFT_THRESHOLD  200
#define RIGHT_THRESHOLD 600
#define UP_THRESHOLD    200
#define DOWN_THRESHOLD  300

BleMouse bleMouse;
int const POT_PIN = 36;  // analog pin used to connect the potentiometer
int potVal = 0;             // variable to read the value from the analog pin
int angle;              // variable to hold the angle for the servo motor

float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleMouse.begin();
  pinMode(VRX_PIN, INPUT);
  pinMode(VRY_PIN, INPUT);
}

void loop() {
  //potVal = analogRead(POT_PIN);
  //angle = floatMap(potVal, 0, 4095, 0, 3.3);

  int valueX = 0; // to store the X-axis value
  int valueY = 0; // to store the Y-axis value

  valueX = analogRead(VRX_PIN);
  valueY = analogRead(VRY_PIN);


  Serial.print("x = ");
  Serial.print(valueX);
  Serial.print(", y = ");
  Serial.println(valueY);

  if(bleMouse.isConnected()) 
  {
    if (valueX < LEFT_THRESHOLD)
      bleMouse.move(1,0);
    else if (valueX > RIGHT_THRESHOLD)
      bleMouse.move(-1,0);

    // check up/down commands
    if (valueY < UP_THRESHOLD)
      bleMouse.move(0,-1);
    else if (valueY > DOWN_THRESHOLD)
      bleMouse.move(0,1);
  }
}