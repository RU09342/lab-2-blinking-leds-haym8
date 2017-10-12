# Multiple Blink
After blinking one LED, the next step was to implement two LEDs blinking at the same time, at different rates. This would be done slightly differently than the first part of the lab, as a second counter would be needed. Instead of using nested loops to delay, the program now will remain running and continually polling the values of the two counters. Each LED will get toggled when the counters hit their respective compare values. Once this happens, the counter value is reset and the process is repeated. Having the counters go up to different values ensured that LEDs would blink at different rates.

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
There is nothing that needs to be done by the user once the program is loaded onto the device. There will be two LEDs blinking at constant rates. Nothing can be done by the user to change these rates.

# Known Errors
Although it is not the case in this project, a possible error that could arise is setting a compare value too high

# Tasks
* [x] Implement more than one counter
* [x] Blink multiple LEDs simultaneously
