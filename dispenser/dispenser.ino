/*
 * dispenser.ino
 * 
 * Author(s):  Don Korte
 * Repository: https://github.com/dnkorte/sanitizer
 * Version: 1.0 Aug 25 2020; first working version
 * 
 * Hand Sanitizer (or soap) dispenser uses peristaltic pump to dispense fluid 
 * when Adafruit VCNL Optical Proximity Sensor observes hand under dispensing 
 * tube. Code runs on ItsyBitsy 32u4 5v version (which accepts 12v Vbat) and 
 * is coded in Arduino IDE. This is all packaged in a 3d printed box, and uses 
 * a standard Jelly Jar to hold the fluid.
 * 
 * Rev 30-Oct-2020 
 *  changed from 3-speed zones to 1-zone with pump speed that varies 
 *  according to duration of dispense -- it starts out fast, then after
 *  4 cycles it slows down for duration of dispense.  this reduces
 *  the amount of drippage
 * 
 * this code requires SparkFun TB6612FNG library for Arduino
 * https://github.com/sparkfun/SparkFun_TB6612FNG_Arduino_Library
 * https://github.com/sparkfun/SparkFun_TB6612FNG_Arduino_Library/blob/master/src/SparkFun_TB6612.h
 * https://github.com/sparkfun/SparkFun_TB6612FNG_Arduino_Library/blob/master/examples/MotorTestRun/MotorTestRun.ino
 * 
 * Adafruit TB6612 board Purchase Link: https://www.adafruit.com/product/2448
 * Adafruit Guide for TB6612: https://learn.adafruit.com/adafruit-tb6612-h-bridge-dc-stepper-motor-driver-breakout
 * (note i was unable to find an Adafruit library for this device running on Arduino IDE)
 * 
 * this code requires Adafruit library for VCLN 4040 Proximity Sensor
 * Guide:  https://learn.adafruit.com/adafruit-vcnl4040-proximity-sensor/overview
 * Purchase Link: https://www.adafruit.com/product/4161
 * 
 * 
 * MIT License
 *
 * Copyright (c) 2020 Don Korte
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
 * SOFTWARE. * 
 */

#include <Adafruit_VCNL4040.h>
#include <SparkFun_TB6612.h>
#define TONEPIN 5

// either 1 or -1 depending on motor wiring polarity
#define DIRECTION -1   

// duration of initial fast pumping allowance
#define ALLOWED_FAST_CYCLES 4   

// Pins for all inputs, keep in mind the PWM defines must be on PWM pins
#define AIN1 11
#define AIN2 10
#define PWMA 9
#define STBY 7

// these constants are used to allow you to make your motor configuration 
// line up with function names like forward.  Value can be 1 or -1
const int offsetA = 1;

// Initializing motors.  The library will allow you to initialize as many
// motors as you have memory for.  If you are using functions like forward
// that take 2 motors as arguements you can either write new functions or
// call the function more than once.
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);

Adafruit_VCNL4040 vcnl4040 = Adafruit_VCNL4040();

int  hand_prox;
bool dispensed_this_cycle, dispensed_last_cycle;

int  fast_cycles_left;

void setup() {
  vcnl4040.begin();
  fast_cycles_left = ALLOWED_FAST_CYCLES;
}

void loop() {  
  
  //Serial.print("Proximity:"); Serial.println(vcnl4040.getProximity());
  //Serial.println("");
  
  /*
   * note proximity value sits about 12-13 if no hand under sensor
   * its about 30 at midrange and 100-200 at very top
   *
   * note speed can range from -255 to +255; 
   * (-50) seems to be a pretty good compromise to avoid squirting
   * big messes vs getting enough quickly enough to satisfy, YMMV
   * 
   * change sign if necessary to account for motor wiring polarity
   * or hose routing
   */

  hand_prox = vcnl4040.getProximity();
  
  if (hand_prox < 15) {
    /* 
     *  no hand sensed, so just ensure motor is off
     */
    noTone(TONEPIN);
    motor1.drive(0);
    dispensed_this_cycle = false;
    fast_cycles_left = ALLOWED_FAST_CYCLES;
        
  } else {
    
    if (fast_cycles_left > 0) {
      fast_cycles_left--;
      /* 
       *  just starting to dispense, so go fast
       */
      tone(TONEPIN, 1500, 50);
      motor1.drive(90 * DIRECTION);      
      delay(500);
      motor1.drive(0);
      dispensed_this_cycle = true;
      delay(25);
    } else {
      /* 
       * we've been dispensing for a while, so slow down 
       */
      tone(TONEPIN, 1000, 50);
      motor1.drive(70 * DIRECTION);      
      delay(300);
      motor1.drive(0);
      dispensed_this_cycle = true;
      delay(100);
     }
    
  } 
  
  if (dispensed_last_cycle && !dispensed_this_cycle) {
      /*
       * when hand LEAVES, suck some fluid back to stop drips
       */
       motor1.drive( (-90) * DIRECTION );      
       delay(700);
       motor1.drive(0);       
  }

  
  dispensed_last_cycle = dispensed_this_cycle;

  /*
   * finally, ensure that there's at least a little
   * bit of delay this loop - just to give the 
   * processor a little time to breath...  :-)
   */
  if (!dispensed_this_cycle) {
    delay(50);
  }
}
