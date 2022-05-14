# REPORT

# ABSTRACT
 -  In this project, A wiper speed control system for an automotive wiper controls and the operational speed of a wiper in
 accordance with rain conditions.
 -  The control system includes a sensor (30) detecting rain or water conditions to produce
 the signal using leds.
 -  The wiper speed is control by the push button with the delay function. An analog signal having
 an amplitude depending upon the detected rain conditions.
 -    The simulation and coding parts are done in "STM32 CUBE-IDE"
 and "CYGWIN TERMINAL". 
 -  The main of this project is to control the wiper system in the car using the STM32F407vg board. 
 In STM32F407VG, using led's, push button and clock frequency to make the cloning of wiper in simulation mode. 
 -  It has several mode of operation using the push button to the control the blinking of leds to indicate the wiper control system.

## INTRODUCTION
  A windscreen wiper or windshield wiper is a device used to remove rain and debris from a windsrceen. Almost all motor vehicle, including trains, aircraft and watercraft, are equipped with such wipers, which are usually an essential requirement. A wiper generally consists of an arm, pivoting at one end and with a long rubber blade attached to the other. The blade is swung back and forth over the glass, pushing water from its surface. The speed is normally adjustable, with several continous speeds and often one or more "intermittent" settings. Most automobiles use two synchronized radial type arms. It takes a lot of force to accelerate the wiper blades back and forth across the windshield so quickly. In order to generate this type of force in this project, a push button is used. The STM32F407VG Discovery Board is used and the arm based programing and design aslo included. The wiper blades are replaced with the different types of LED's to show the wiper swung down and up.
  
## Block Diagram

![Untitled Diagram (3)](https://user-images.githubusercontent.com/101013448/168089335-1ce41f5c-acf3-414c-b5c6-de151ea8c815.jpg)

## Flow Chart

![Diagram](https://user-images.githubusercontent.com/101013448/168427186-09bb7878-7a0a-4e59-b6cf-db38c6350788.jpg)

## Components Required
**STM32F407VG Discovery Board** - 
The STM32F407G-DISC1 is a Discovery Kit allows users to easily develop applications with the STM32F407 high performance microcontrollers with ARM cortex-M4 32-bit core. It includes everything required either for beginners or for experienced users to get quickly started.

![sstm32f4](https://user-images.githubusercontent.com/101013448/168443870-04415df5-e1ac-4e3d-bb17-5fcf0b8cd121.jpg)

**Push Button** - A Push Button switch is a type of switch which consists of a simple electric mechanism or air switch mechanism to turn something on or off. Depending on model they could operate with momentary or latching action function. The button is place inside the STM32F407VG Discovery Board.

![image](https://user-images.githubusercontent.com/101013448/168431098-91948ee5-fa7e-4f69-b0ac-8ce07b535835.png)

**LED** - LED lights come in a range of colours from soft yellows to bright whites. Warm light tends toward yellows, reds, and oranges. Cool light appears blue or greenish. In between the two, light appears crisp and white.

![image](https://user-images.githubusercontent.com/101013448/168430084-b322db24-d4a2-4afe-beef-46aaa7160a41.png)

## Procedure 
* **Start**: Setting IDE's and STM32F407VG Discovery Board to initialize the Push Button and LED Pin.
* **Ignition Key Position at ACC**: The Red LED is ON, if the user button is pressed and held for 2 secs
* **Wiper ON: Wiper is OFF**: On press of the user input, Blue, Green and Orange LEDs come ON one at a time with the set frequency, The frequency changes on every alternate key press, 3 frequency levels with 1, 4 and 8 Hz.
* **Wiper OFF**: Wiper is ON: The LED glow pattern stops on the 4th press; the wiper action starts next press onwards as mentioned in step 2
Ignition Key Position at Lock: The Red LED is OFF, if the user button is pressed and held for 2 secs.
* **Compile And Run**:  Compile the code and set the qemu emulator in the cygwin software to Run.

## Conclusion
  Thus, the **WIPER CONTROL SYSTEM** is implemented using STM32F407VG to get the desire output.
