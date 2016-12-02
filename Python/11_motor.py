#!/usr/bin/env python

import RPi.GPIO as GPIO
import time

# Set up pins
MotorPin1   = 17
MotorPin2   = 18
MotorEnable = 27

def print_message():
	print ("========================================")
	print ("|                Motor                 |")
	print ("|    ------------------------------    |")
	print ("|     Motor pin 1 connect to GPIO0     |")
	print ("|     Motor pin 2 connect to GPIO1     |")
	print ("|     Motor enable connect to GPIO2    |")
	print ("|                                      |")
	print ("|         Controlling a motor          |")
	print ("|                                      |")
	print ("|                            SunFounder|")
	print ("========================================\n")
	print 'Program is running...'
	print 'Please press Ctrl+C to end the program...'
	raw_input ("Press Enter to begin\n")

def setup():
	# Set the GPIO modes to BCM Numbering
	GPIO.setmode(GPIO.BCM)
	# Set pins to output
	GPIO.setup(MotorPin1, GPIO.OUT)
	GPIO.setup(MotorPin2, GPIO.OUT)
	GPIO.setup(MotorEnable, GPIO.OUT, initial=GPIO.LOW)

# Define a motor function to spin the motor
# direction should be 
# 1(clockwise), 0(stop), -1(counterclockwise)
def motor(direction):
	# Clockwise
	if direction == 1:
		# Set direction
		GPIO.output(MotorPin1, GPIO.HIGH)
		GPIO.output(MotorPin2, GPIO.LOW)
		# Enable the motor
		GPIO.output(MotorEnable, GPIO.HIGH)
		print "Clockwise"
	# Counterclockwise
	if direction == -1:
		# Set direction
		GPIO.output(MotorPin1, GPIO.LOW)
		GPIO.output(MotorPin2, GPIO.HIGH)
		# Enable the motor
		GPIO.output(MotorEnable, GPIO.HIGH)
		print "Counterclockwise"
	# Stop
	if direction == 0:
		# Disable the motor
		GPIO.output(MotorEnable, GPIO.LOW)
		print "Stop"

def main():
	print_message()
	# Define a dictionary to make the script more readable
	# CW as clockwise, CCW as counterclockwise, STOP as stop
	directions = {'CW': 1, 'CCW': -1, 'STOP': 0}
	while True:
		# Clockwise
		motor(directions['CW'])
		time.sleep(5)
		# Stop
		motor(directions['STOP'])
		time.sleep(5)
		# Anticlockwise
		motor(directions['CCW'])
		time.sleep(5)
		# Stop
		motor(directions['STOP'])
		time.sleep(5)

def destroy():
	# Stop the motor
	GPIO.output(MotorEnable, GPIO.LOW)
	# Release resource
	GPIO.cleanup()    

# If run this script directly, do:
if __name__ == '__main__':
	setup()
	try:
		main()
	# When 'Ctrl+C' is pressed, the child program 
	# destroy() will be executed.
	except KeyboardInterrupt:
		destroy()