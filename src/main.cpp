#include <BleMouse.h>
#include <Arduino.h>
#include <ezButton.h>

#define VRX_PIN  34 // ESP32 pin GPIO39 (ADC3) connected to VRX pin
#define VRY_PIN  35 // ESP32 pin GPIO36 (ADC0) connected to VRY pin
#define SW_PIN   17 // ESP32 pin GPIO17 connected to SW  pin

ezButton button(SW_PIN);

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

  button.setDebounceTime(50);
}

void loop() {
  button.loop();

  buttonVal = digitalRead(BUTTON_PIN);
  potVal = analogRead(POT_PIN);

  //Serial.print(", buttonVal: ");
  //Serial.print(buttonVal);

  //Serial.print("potVal: ");
  //Serial.print(potVal);

  angle = floatMap(potVal, 0, 4095, 0, 3.3);

  //Serial.print(", angle: ");
  //Serial.println(angle);

  if(bleMouse.isConnected()) 
  {
    //Serial.println("Move mouse pointer right");
    if(buttonVal==0)
    {
      bleMouse.move(1+angle,0);
    }
  }

  int valueX = 0; // to store the X-axis value
  int valueY = 0; // to store the Y-axis value
  int bValue = 0; // To store value of the button

  valueX = analogRead(VRX_PIN);
  valueY = analogRead(VRY_PIN);

  // Read the button value
  bValue = button.getState();

  if (button.isPressed()) {
    //Serial.println("The button is pressed");
    // TODO do something here
  }

  if (button.isReleased()) {
    //Serial.println("The button is released");
    // TODO do something here
  }

  // print data to Serial Monitor on Arduino IDE
  Serial.print("x = ");
  Serial.print(valueX);
  Serial.print(", y = ");
  Serial.println(valueY);
  //Serial.print(" : button = ");
  //Serial.println(bValue);
}