#!/usr/bin/env python
import RPi.GPIO as GPIO
import time
# Set #17 as LED pin
LedPin = 17
# Set #18 as button pin
BtnPin = 18

# Set Led status to True(OFF)
Led_status = True

# Define a function to print message at the beginning
def print_message():
	print 'Program is running...'
	print 'Please press Ctrl+C to end the program...'

# Define a setup function for some setup
def setup():
	# Set the GPIO modes to BCM Numbering
	GPIO.setmode(GPIO.BCM)
	# Set LedPin's mode to output, 
	# and initial level to high (3.3v)
	GPIO.setup(LedPin, GPIO.OUT, initial=GPIO.HIGH)
	# Set BtnPin's mode to input, 
	# and pull up to high (3.3V)
	GPIO.setup(BtnPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)
	# Set up a falling detect on BtnPin, 
	# and callback function to swLed
	GPIO.add_event_detect(BtnPin, GPIO.FALLING, callback=swLed)

# Define a callback function for button callback
def swLed(ev=None):
	global Led_status
	# Switch led status(on-->off; off-->on)
	Led_status = not Led_status
	GPIO.output(LedPin, Led_status)
	if Led_status:
		print 'LED OFF...'
	else:
		print '...LED ON'

# Define a main function for main process
def main():
	# Print messages
	print_message()
	while True:
		# Don't do anything.
		time.sleep(1)

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

