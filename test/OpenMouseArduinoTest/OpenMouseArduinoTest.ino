int const potPin = 36;  // analog pin used to connect the potentiometer
int potVal;             // variable to read the value from the analog pin
int angle;              // variable to hold the angle for the servo motor
int switchstate = 0;
int button=21;

float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
  Serial.begin(9600);  // open a serial connection to your computer
  analogSetAttenuation(ADC_11db);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  switchstate = digitalRead(button);
  potVal = analogRead(potPin);  // read the value of the potentiometer
  // print out the value to the Serial Monitor
  Serial.print("potVal: ");
  Serial.print(potVal);

  Serial.print(", switchstate: ");
  Serial.print(switchstate);

  // scale the numbers from the pot
  //angle = map(potVal, 0, 1023, 0, 179);
  float angle = floatMap(potVal, 0, 4095, 0, 3.3);

  // print out the angle for the servo motor
  Serial.print(", angle: ");
  Serial.println(angle);

  // wait for the servo to get there
  delay(15);
}
