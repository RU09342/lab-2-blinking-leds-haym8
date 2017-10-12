## Mitchell Hay

# Off-Board Blink

![Offboard Blink](Offboard_Blink_MSP430.gif)

# Devices
* MSP430F5529
* MSP430FR2311
* MSP430FR5994
* MSP430FR6989
* MSP430G2553

# Getting Started
## Dependencies
Each device requires no outside dependencies. Everything needed to run the program is included in the folder. Each folder is labeled with the device it is meant for.
## Setup
Each of the device projects in this part of the lab can be imported into Code Composer Studio and run from there. To import it, open CCS and select File -> Import -> Code Composer Studio -> CCS Project and select the desired directory.

# Functionality
## Usage
There is nothing that needs to be done by the user once the program is loaded onto the device. There will be an LED blinking at a constant rate. Nothing can be done to change this rate, although that idea is covered in a different lab. 

## Extra Work
The extra work done for this part of the lab was changing the LED blink speed over a UART connection. The inputs are 's' for slow speed
blink, 'm' for medium speed blink, 'f' for fast speed blink, and 'o' for off. This was implemented on the MSP430F5529 and can be run by 
importing the project into Code Composer Studio. A USB to WART cable was used along with PuTTy in order to communicate with the device.

# Known Errors
Connecting the USB to UART cable incorrectly to the development board will result in an error. The correct way to connect the UART cable is to connect the transmit cable of the UART cable to the receive pin of the board. Do the opposite with the receive cable, and connect the ground wire to a ground pin on the board. Do NOT connect the 5V wire to the board, as it could overload and damage it.

# Tasks
* [x] Learn how MSP430 device registers work
* [x] Implement one way to delay a program
* [x] Transmit and Recieve data over UART
