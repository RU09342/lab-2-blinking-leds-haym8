## Mitchell Hay

# Button Blink
Now the user will have some input on the LED blinking. The on-board button will now act as a switch, turning the LED off when the button is pressed. The LED will stay off until the button is released. The handling of the button pressing is done by polling, or constantly checking the status of the button. This is not the idea way of handling button clicks, although it is a good start in learning one of the two ways to handle I/O.

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
There is nothing that needs to be done by the user once the program is loaded onto the device. There will be an LED blinking at a constant rate. Nothing can be done to change this rate, although that idea is covered in a different part of the lab. 

## Extra Work
The extra work implemented in this part of the lab was Button Based Speed Control. This was done by polling the button press, and adding to a counter when it was pressed. The counter had values of 0 through 4. 0 was considered off, and 4 was the highest speed of LED blinking. This code was made for the MSP430G2553. There is a small delay during the button poll to account for button debouncing.

# Known Errors
One problem with the current program is something called debouncing. This happens when the button is pressed, as pressing a button does not always result in clean contact with the other contact. This debouncing could cause the LED to show unexpected values. Debouncing is a problem that is more thoroughly handled in a later lab.

# Tasks
* [x] Learn about I/O using a button
* [x] Use Polling to blink LED

