/*
 *****************************************************************************
 * SanitizerTest.ino
 *
 * test program for motor attached to Adafruit TB6612 motor driver board
 * this code is lifted (and slightly modified from)from the Sparkfun TB6612 library
 * as described at:
 * https://github.com/sparkfun/SparkFun_TB6612FNG_Arduino_Library
 * https://github.com/sparkfun/SparkFun_TB6612FNG_Arduino_Library/blob/master/src/SparkFun_TB6612.h
 * https://github.com/sparkfun/SparkFun_TB6612FNG_Arduino_Library/blob/master/examples/MotorTestRun/MotorTestRun.ino
 * 
 * Adafruit TB6612 board Purchase Link: https://www.adafruit.com/product/2448
 * Adafruit Guide for TB6612: https://learn.adafruit.com/adafruit-tb6612-h-bridge-dc-stepper-motor-driver-breakout
 * (note i was unable to find an Adafruit library for this device running on Arduino IDE)
 * 
*****************************************************************************
*/

// This is the library for the TB6612 that contains the class Motor and all the
// functions
#include <SparkFun_TB6612.h>

// Pins for all inputs, keep in mind the PWM defines must be on PWM pins
// the default pins listed are the ones used on the Redbot (ROB-12097) with
// the exception of STBY which the Redbot controls with a physical switch
#define AIN1 11
#define AIN2 10
#define PWMA 9
#define STBY 7
#define TONEPIN 5

// these constants are used to allow you to make your motor configuration 
// line up with function names like forward.  Value can be 1 or -1
const int offsetA = 1;
const int offsetB = 1;


// Initializing motors.  The library will allow you to initialize as many
// motors as you have memory for.  If you are using functions like forward
// that take 2 motors as arguements you can either write new functions or
// call the function more than once.
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);

void setup()
{
 //Nothing here
}


void loop()
{
   //Use of the drive function which takes as arguements the speed
   //and optional duration.  A negative speed will cause it to go
   //backwards.  Speed can be from -255 to 255.  Also use of the 
   //brake function which takes no arguements.
   //motor1.drive(100,1000);
   //motor1.drive(-100,1000);
   //motor1.brake();
   
   tone(TONEPIN, 1000, 500);
   delay(1000);   
   tone(TONEPIN, 2000, 500);
   delay(1000);   
   tone(TONEPIN, 3000, 500);
   delay(1000);     
}
