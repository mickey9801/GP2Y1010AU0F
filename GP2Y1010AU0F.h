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

#ifndef GP2Y1010AU0F_H
#define GP2Y1010AU0F_H

#include <Arduino.h>

class GP2Y1010AU0F {
  private:
    uint8_t        _LEDPin;
    uint8_t        _measurePin;
    int            _samplingTime     = 280;
    int            _deltaTime        = 40;
    int            _sleepTime        = 9680;
    float          _VCC              = 5.0;

  public:
    GP2Y1010AU0F(uint8_t ledPin, uint8_t measurePin);
    bool begin();
    float read();
};

#endif /* GP2Y1010AU0F_H */
