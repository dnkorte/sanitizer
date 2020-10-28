# Hand Sanitizer Dispenser

<h1 align="center">
	<img width="853" src="https://github.com/dnkorte/sanitizer/blob/master/pictures/picture1_front.jpg" alt="Picture of Hand Sanitizer Dispenser"><br>Hand Sanitizer Dispenser
</h1>


Hand Sanitizer (or soap) dispenser uses peristaltic pump to dispense fluid when Adafruit VCNL Optical Proximity Sensor observes hand under dispensing tube.  Code runs on an Adafruit ItsyBitsy 32u4 5v version (which may be powered by 12v Vbat) and is coded in Arduino IDE.  This is all packaged in a 3d printed container, and uses a standard Jelly Jar to hold the fluid.

Video of dispenser in action:  https://youtu.be/iYxsz3DUehM 
Photo Album: https://photos.app.goo.gl/EdRW3g8P56AdBAn6A

Some photos of the device are in the "photos" folder here on github; a larger collection is available in the linked photo album.  The Arduino software is in the "dispenser" folder here.  Printed Circuit board gerber files and schematic are in the "hardware" folder.  Note that it is important to use only the 5 Volt version of the 32u4 Itsy Bitsy, as this device allows a wider range of power input (the 5v 32u4 allows up to 16 volts input, but the normal ones only allow 6v input.  This circuit powers the Itsy Bitsy from the same 12v power block that runs the motor).

The device is setup with 3 "zones" for hand position under the nozzle, each of which triggers a different speed of pump.  If you put your hand in the window close to the bottom it provides a pretty slow and "intermittent" pumping action.  Mid-range hand pumps more quickly and gives a more satisying amount of sanitizer for normal use.  If you move your hand up to the very top of the range (almost touching the top) it turns on motor at high speed -- this is good for priming the pump after it sits for a long time or if you've just refilled the jar.  Note that no matter which zone you use, when you pull your hand out of the dispense area it runs the pump backwards for a short period to reduce the amount of drippage.  

The device plays a series of beeps through the included speaker while it is dispensing.  

### Bill of Materials

| Description | Supplier | Notes |
| ----------- | -------- | ----- | 
| [ItsyBitsy 32u4 5v](https://www.adafruit.com/product/3677) | Adafruit | must be 5v version for power supply [Guide](https://learn.adafruit.com/introducting-itsy-bitsy-32u4/overview) |
| [TB6612 Motor Driver](https://www.adafruit.com/product/2448) | Adafruit | [Guide](https://learn.adafruit.com/adafruit-tb6612-h-bridge-dc-stepper-motor-driver-breakout) |
| [VCNL 4040 Lux/Proximity Sensor](https://learn.adafruit.com/adafruit-vcnl4040-proximity-sensor/) | Adafruit | [Guide](https://www.adafruit.com/product/4161)
| [2.1mm Barrel Jack](https://www.adafruit.com/product/610) | Adafruit |
| [Mini Oval Speaker](https://www.adafruit.com/product/3923) | Adafruit | note: will cut off connector and replace |
| [Peristaltic Pump 12v with hose](https://www.amazon.com/Peristaltic-Liquid-Dosing-Silicone-Tubing/dp/B075VN1QZM) | Amazon | includes 1m silicone tubing & 2 barbed connectors; 100 mL/min 300 mA |
| [12v 2A power supply with Barrel plug](https://www.amazon.com/TMEZON-Power-Adapter-Supply-2-1mm/dp/B00Q2E5IXW) | Amazon  |
| [2-pin Screw Terminal Block](https://www.amazon.com/dp/B01C3DGIBQ/) | Amazon | 2 pcs req'd; 3.5mm pitch |
| [47 uF Electrolytic Capacitor](https://www.adafruit.com/product/2194) | Adafruit | stand-up tubular, value not critical, just for DC blocking
| [Female Header Strip](https://www.adafruit.com/product/598) | Adafruit | need  to cut 2 14 pin sections |
| [Pin Header strip (male)](https://www.adafruit.com/product/392) | Adafruit | need to cut 3-pin, and 4-pin sections |
| [2-pin Dupont Connector body](https://www.amazon.com/Hilitchi-2-54mm-Headers-Connector-Housing/dp/B012EOO9Q0/) | Amazon | with female pins (note this assortment has 2- and 4- pin bodies as well as male pin header strip; you will need a [crimper](https://www.adafruit.com/product/350) to assemble these)|
| [4-pin Dupont Connector body](https://www.amazon.com/Hilitchi-2-54mm-Headers-Connector-Housing/dp/B012EOO9Q0/) | Amazon | with female pins |
| M3 x 8mm screws | Amazon | 12 pcs (lid-to-box, hose clamps to tower, tower-to-lid) |
| M3 x 6mm screws | Amazon | 4 pcs (to mount PCB) |
| M2.5 x 6mm screws | Amazon | 4 pcs (for Proximity Sensor) |
| [M3 Threaded Insert](https://www.mcmaster.com/94459A130/) | McMaster-Carr | 14 pcs (lid-to-box, hose clamps, pump, PCB-to-box) |
| [M2.5 Threaded Insert](https://www.amazon.com/Products-Insert-Heat-Sink-Injection/dp/B07HKT5W7S/) | Amazon | 4 pcs (for Proximity Sensor) |
| Glass Jelly Jar | local grocery | standard 1-pint jelly / jam jar as used for canning |

### 3d Printed Parts

### Printed Circuit Board
<h1 align="center">
	<img width="480" src="https://github.com/dnkorte/sanitizer/blob/master/hardware/pHand_Sanitizer_PCB_top.png" alt="Picture of Hand Sanitizer Dispenser">
</h1>