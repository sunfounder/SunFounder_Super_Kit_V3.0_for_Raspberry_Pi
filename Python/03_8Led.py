#!/usr/bin/env python3

import RPi.GPIO as GPIO
import time
from sys import version_info

if version_info.major == 3:
	raw_input = input


# Set 8 Pins for 8 LEDs.
LedPins = [17, 18, 27, 22, 23, 24, 25, 4]

# Define a function to print message at the beginning
def print_message():
	print ("========================================")
	print ("|                8 LEDs                |")
	print ("|    ------------------------------    |")
	print ("|         LED0 connect to GPIO0        |")
	print ("|         LED1 connect to GPIO1        |")
	print ("|         LED2 connect to GPIO2        |")
	print ("|         LED3 connect to GPIO3        |")
	print ("|         LED4 connect to GPIO4        |")
	print ("|         LED5 connect to GPIO5        |")
	print ("|         LED6 connect to GPIO6        |")
	print ("|         LED7 connect to GPIO7        |")
	print ("|                                      |")
	print ("|            Flow LED effect           |")
	print ("|                                      |")
	print ("|                            SunFounder|")
	print ("========================================\n")
	print ("Program is running...")
	print ("Please press Ctrl+C to end the program...")
	raw_input ("Press Enter to begin\n")

# Define a setup function for some setup
def setup():
	# Set the GPIO modes to BCM Numbering
	GPIO.setmode(GPIO.BCM)
	# Set all LedPin's mode to output, 
	# and initial level to High(3.3v)
	GPIO.setup(LedPins, GPIO.OUT, initial=GPIO.HIGH)

# Define a main function for main process
def main():
	# Print messages
	print_message()
	leds = ['-', '-', '-', '-', '-', '-', '-', '-']

	while True:
		# Turn LED on from left to right
		print ("From left to right.")
		for pin in LedPins:
			#print pin
			GPIO.output(pin, GPIO.LOW)
			leds[LedPins.index(pin)] = 0	# Show which led is on
			print (leds)
			time.sleep(0.1)
			GPIO.output(pin, GPIO.HIGH)
			leds[LedPins.index(pin)] = '-'	# Show the led is off

		# Turn LED off from right to left
		print ("From right to left.")
		for pin in reversed(LedPins):
			#print pin
			GPIO.output(pin, GPIO.LOW)
			leds[LedPins.index(pin)] = 0	# Show which led is on
			print (leds)
			time.sleep(0.1)
			GPIO.output(pin, GPIO.HIGH)
			leds[LedPins.index(pin)] = '-'	# Show the led is off

# Define a destroy function for clean up everything after
# the script finished 
def destroy():
	# Turn off all LEDs
	GPIO.output(LedPins, GPIO.HIGH)
	# Release resource
	GPIO.cleanup()

# If run this script directly, do:
if __name__ == '__main__':
	setup()
	try:
		main()
	# When 'Ctrl+C' is pressed, the child program 
	# destroy() will be  executed.
	except KeyboardInterrupt:
		destroy()
