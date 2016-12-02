#!/usr/bin/env python

import RPi.GPIO as GPIO
import time

# Set #17 as LED pin
LedPin = 17

# Define a function to print message at the beginning
def print_message():
	print ("========================================")
	print ("|              Blink LED               |")
	print ("|    ------------------------------    |")
	print ("|         LED connect to GPIO0         |")
	print ("|                                      |")
	print ("|        LED will Blink at 500ms       |")
	print ("|                                      |")
	print ("|                            SunFounder|")
	print ("========================================\n")
	print 'Program is running...'
	print 'Please press Ctrl+C to end the program...'
	raw_input ("Press Enter to begin\n")

# Define a setup function for some setup
def setup():
	# Set the GPIO modes to BCM Numbering
	GPIO.setmode(GPIO.BCM)
	# Set LedPin's mode to output, 
	# and initial level to High(3.3v)
	GPIO.setup(LedPin, GPIO.OUT, initial=GPIO.HIGH)

# Define a main function for main process
def main():
	# Print messages
	print_message()
	while True:
		print '...LED ON'
		# Turn on LED
		GPIO.output(LedPin, GPIO.LOW)
		time.sleep(0.5)
		print 'LED OFF...'
		# Turn off LED
		GPIO.output(LedPin, GPIO.HIGH) 
		time.sleep(0.5)

# Define a destroy function for clean up everything after
# the script finished 
def destroy():
	# Turn off LED
	GPIO.output(LedPin, GPIO.HIGH)
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
