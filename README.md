# Sharp GP2Y1010AU0F Dust Sensor Library
This is a wrapper library for Sharp GP2Y1010AU0F Optical Dust Sensor. The library is built base on [this post](http://www.howmuchsnow.com/arduino/airquality/).

## Installation
1. Download ZIP file of this repository;
2. In the Arduino IDE, choose Sketch/Include Library/Add Zip Library;
3. Navigate to the ZIP file, and click Open, the library will be placed in \[Arduino directory\]/libraries/GP2Y1010AU0F/;
4. you should find the "GP2Y1010AU0F" in Sketch/Include Library from menu.

## APIs
### GP2Y1010AU0F
The constructor. Return a GP2Y1010AU0F object.

```c++
GP2Y1010AU0F::GP2Y1010AU0F(uint8_t ledPin, uint8_t measurePin)
```

Parameters|Type|Description
---|---|---
ledPin|unsigned int|Sensor infrared LED pin number
measurePin|unsigned int|Sensor analog measure pin number

### begin
Setup sensor object. Return `true` when done.

```c++
bool GP2Y1010AU0F::begin()
```

### read
Simply read the current dust density. Unit: ug/m<sup>3</sup>

```c++
float GP2Y1010AU0F::read()
```

## Usage Example
```c++
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
```

## Reference
[Sharp GP2Y1010AU0F data sheet](https://www.sparkfun.com/datasheets/Sensors/gp2y1010au_e.pdf)  
[Air Quality Monitoring](http://www.howmuchsnow.com/arduino/airquality/)
