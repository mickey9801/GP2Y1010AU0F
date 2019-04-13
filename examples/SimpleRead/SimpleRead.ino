/**
 * Example for using GP2Y1010AU0F Dust Sensor library
 * Created by Mickey Chan
 */

#include <GP2Y1010AU0F.h>

int measurePin = A0;   // Connect dust sensor analog measure pin to Arduino A0 pin
int ledPin     = 2;    // Connect dust sensor LED pin to Arduino pin 2

GP2Y1010AU0F dustSensor(ledPin, measurePin); // Construct dust sensor global object
float dustDensity = 0;

void setup() {
  Serial.begin(115200);
  Serial.println(F("GP2Y1010AU0F Dust Sensor Library Example"));

  dustSensor.begin();
}

void loop() {
  dustDensity = dustSensor.read();
  
  Serial.print("Dust Density = ");
  Serial.print(dustDensity);
  Serial.println(" ug/m3");

  delay(5000);
}
