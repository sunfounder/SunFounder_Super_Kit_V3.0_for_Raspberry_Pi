#!/usr/bin/env python
import RPi.GPIO as GPIO
import time

# Set #17 as LED pin
LedPin = 18

def print_message():
	print 'Program is running...'
	print 'Please press Ctrl+C to end the program...'

def setup():
	global pLed
	# Set the GPIO modes to BCM Numbering
	GPIO.setmode(GPIO.BCM)
	# Set LedPin's mode to output, 
	# and initial level to low (0v)


	GPIO.setup(LedPin, GPIO.OUT, initial=GPIO.LOW)
	# Set pLed as pwm output and frequece to 1KHz
	pLed = GPIO.PWM(LedPin, 1000)
	# Set pLed begin with value 0
	pLed.start(0)

def main():
	print_message()
	# Set increase/decrease step
	step =2 
	# Set delay time.
	delay = 0.05
	while True:
		# Increase duty cycle from 0 to 100
		for dc in range(0, 101, step):
			# Change duty cycle to dc
			pLed.ChangeDutyCycle(dc)
			time.sleep(delay)
		time.sleep(1)
		# decrease duty cycle from 100 to 0
		for dc in range(100, -1, -step):
			# Change duty cycle to dc
			pLed.ChangeDutyCycle(dc)
			time.sleep(delay)
		#time.sleep(1)

def destroy():
	# Stop pLed
	pLed.stop()
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
