#!/usr/bin/env python3

import RPi.GPIO as GPIO
import time
from sys import version_info

if version_info.major == 3:
	raw_input = input


# Set #17 as 4N35 pin
Pin_4N35 = 17

# Define a function to print message at the beginning
def print_message():
	print ("========================================")
	print ("|                 4N35                 |")
	print ("|    ------------------------------    |")
	print ("|      LED connect to 4N35 pin5;       |")
	print ("|      gpio0 connect to 4N35 pin2;     |")
	print ("|                                      |")
	print ("|     4N35 to contral led blinking.    |")
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
	# Set Pin_4N35's mode to output, 
	# and initial level to High(3.3v)
	GPIO.setup(Pin_4N35, GPIO.OUT, initial=GPIO.HIGH)

# Define a main function for main process
def main():
	# Print messages
	print_message()
	while True:
		print ("...LED ON")
		# Turn on LED
		GPIO.output(Pin_4N35, GPIO.LOW)
		time.sleep(0.5)
		print ("LED OFF...")
		# Turn off LED
		GPIO.output(Pin_4N35, GPIO.HIGH) 
		time.sleep(0.5)

# Define a destroy function for clean up everything after
# the script finished 
def destroy():
	# Turn off LED
	GPIO.output(Pin_4N35, GPIO.HIGH)
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
