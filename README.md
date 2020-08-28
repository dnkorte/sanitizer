# Hand Sanitizer Dispenser

<h1 align="center">
	<img width="853" src="https://github.com/dnkorte/sanitizer/blob/master/pictures/picture1_front.jpg" alt="Picture of Hand Sanitizer Dispenser"><br>Hand Sanitizer Dispenser
</h1>


Hand Sanitizer (or soap) dispenser uses peristaltic pump to dispense fluid when Adafruit VCNL Optical Proximity Sensor observes hand under dispensing tube.  Code runs on an Adafruit ItsyBitsy 32u4 5v version (which may be powered by 12v Vbat) and is coded in Arduino IDE.  This is all packaged in a 3d printed container, and uses a standard Jelly Jar to hold the fluid.

Video of dispenser in action:  https://youtu.be/iYxsz3DUehM 

### Bill of Materials

Description | Supplier|Notes
----------- | -------------- 
| [ItsyBitsy 32u4 5v](https://www.adafruit.com/product/3677) | Adafruit | must be 5v version for power supply [Guide](https://learn.adafruit.com/introducting-itsy-bitsy-32u4/overview) |
| [TB6612 Motor Driver](https://www.adafruit.com/product/2448) | Adafruit | [Guide](https://learn.adafruit.com/adafruit-tb6612-h-bridge-dc-stepper-motor-driver-breakout) |
| [VCNL 4040 Lux/Proximity Sensor](https://learn.adafruit.com/adafruit-vcnl4040-proximity-sensor/) | Adafruit | [Guide](https://www.adafruit.com/product/4161)
| [2.1mm Barrel Jack](https://www.adafruit.com/product/610) | Adafruit |
| [Mini Oval Speaker](https://www.adafruit.com/product/3923) | Adafruit | note: will cut off connector and replace |
| [Peristaltic Pump 12v with hose](https://www.amazon.com/Peristaltic-Liquid-Dosing-Silicone-Tubing/dp/B075VN1QZM) | Amazon | includes 1m silicone tubing & 2 barbed connectors; 100 mL/min 300 mA |
| [12v 2A power supply with Barrel plug](https://www.amazon.com/TMEZON-Power-Adapter-Supply-2-1mm/dp/B00Q2E5IXW) | Amazon  |
| [2-pin Screw Terminal Block](https://www.amazon.com/dp/B01C3DGIBQ/) | Amazon | 2 pcs req'd; 3.5mm pitch |
| Female Header Strip | | need 2 14 pin sections |
| Pin Header strip (male) | | need 3-pin, and 4-pin sections |
| 2-pin Dupont Connector body | | with famale pins |
| 4-pin Dupont Connector | | with female pins |
| M3 x 8mm screws | | 8 pcs (lid-to-box, hose clamps to tower) |
| M3 x 6mm screws | | 4 pcs (to mount PCB) |
| M2.5 x 6mm screws | | 4 pcs (for Proximity Sensor) |
| M3 Threaded Insert | McMaster-Carr | 14 pcs (lid-to-box, hose clamps, pump, PCB-to-box) |
| M2.5 Threaded Insert | McMaster-Carr | 4 pcs (for Proximity Sensor) |
