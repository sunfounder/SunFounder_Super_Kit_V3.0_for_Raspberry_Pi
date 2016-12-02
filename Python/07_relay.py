#!/usr/bin/env python

import RPi.GPIO as GPIO
import time


# GPIO0 connect to relay's control pin
# led connect to relay's NormalOpen pin
# 5v connect to relay's com pin
# Set #17 as contral pin
relayPin = 17

# Define a function to print message at the beginning
def print_message():
	print ("========================================")
	print ("|                 Relay                |")
	print ("|    ------------------------------    |")
	print ("| GPIO0 connect to relay's control pin |")
	print ("| led connect to relay's NormalOpen pin|")
	print ("|  5v connect to relay's com pin       |")
	print ("|                                      |")
	print ("|      Make relay to contral a led     |")
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
	# Set relayPin's mode to output, 
	# and initial level to High(3.3v)
	GPIO.setup(relayPin, GPIO.OUT, initial=GPIO.HIGH)

# Define a main function for main process
def main():
	# Print messages
	print_message()
	while True:
		print '...Relay close'
		# Tick
		GPIO.output(relayPin, GPIO.LOW)
		time.sleep(1)
		print 'Relay open...'
		# Tock
		GPIO.output(relayPin, GPIO.HIGH) 
		time.sleep(1)

# Define a destroy function for clean up everything after
# the script finished 
def destroy():
	# Turn off LED
	GPIO.output(relayPin, GPIO.HIGH)
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
