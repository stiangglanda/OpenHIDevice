#include <BleMouse.h>
#include <Arduino.h>

BleMouse bleMouse;
int const POT_PIN = 36;  // analog pin used to connect the potentiometer
int potVal = 0;             // variable to read the value from the analog pin
int angle;              // variable to hold the angle for the servo motor
int buttonVal = 0;
int const BUTTON_PIN=21;

float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleMouse.begin();
  analogSetAttenuation(ADC_11db);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  buttonVal = digitalRead(BUTTON_PIN);
  potVal = analogRead(POT_PIN);

  Serial.print(", buttonVal: ");
  Serial.print(buttonVal);

  Serial.print("potVal: ");
  Serial.print(potVal);

  angle = floatMap(potVal, 0, 4095, 0, 3.3);

  Serial.print(", angle: ");
  Serial.println(angle);

  if(bleMouse.isConnected()) 
  {
    Serial.println("Move mouse pointer right");
    if(buttonVal==0)
    {
      bleMouse.move(1+angle,0);
    }
  }
}