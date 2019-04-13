/**
 * Sharp GP2Y1010AU0F Dust Sensor Library
 * Copyright (c) 2019 Mickey Chan
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 * Developed for Arduino-ESP32
 * Created by Mickey Chan (developer AT comicparty.com)
 * 
 */

#include <Arduino.h>
#include "GP2Y1010AU0F.h"

/**
 * Constructor
 * @param ledPin     Sensor infrared LED pin number
 * @param measurePin Sensor analog measure pin number
 * @return GP2Y1010AU0F object
 */
GP2Y1010AU0F::GP2Y1010AU0F(uint8_t ledPin, uint8_t measurePin) {
  this->_LEDPin = ledPin;
  this->_measurePin = measurePin;
}

/**
 * Setup sensor object
 * @return true when done
 */
bool GP2Y1010AU0F::begin() {
  pinMode(this->_LEDPin, OUTPUT);
  digitalWrite(this->_LEDPin, HIGH); // power off the LED
  return true;
}

/**
 * Simply read the current dust density.
 * @return Current dust density. Unit: ug/m3
 */
float GP2Y1010AU0F::read() {
  float voMeasured  = 0;
  float calcVoltage = 0;
  float dustDensity = 0;
  
  digitalWrite(this->_LEDPin, LOW); // power on the LED
  delayMicroseconds(this->_samplingTime);
  voMeasured = analogRead(this->_measurePin); // read the dust value
  delayMicroseconds(this->_deltaTime);
  digitalWrite(this->_LEDPin, HIGH); // turn the LED off
  delayMicroseconds(this->_sleepTime);

  // 0 - 5V mapped to 0 - 1023 integer values
  // recover voltage
  calcVoltage = voMeasured * (this->_VCC / 1024.0);
  // linear equation taken from http://www.howmuchsnow.com/arduino/airquality/
  dustDensity = (0.17 * calcVoltage - 0.1) * 1000.0;
  return dustDensity;
}
