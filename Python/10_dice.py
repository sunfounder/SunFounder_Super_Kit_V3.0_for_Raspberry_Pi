'''
**********************************************************************
* Filename    : Dice.py
* Description : press a button to roll dice.
* Author      : Cavon
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Update      : Cavon    2016-08-29    import from dice.c
**********************************************************************
'''
import RPi.GPIO as GPIO
import time
import random

SDI = 17     # Serial data input
RCLK  = 18   # Memory clock input(STCP)
SRCLK = 27   # Shift register clock input(SHCP)

TouchPin = 22

SegCode = [0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d]
flag = 0

def setup():
	GPIO.setmode(GPIO.BCM)
	GPIO.setup(SDI, GPIO.OUT)   # Make P0 output
	GPIO.setup(RCLK, GPIO.OUT)  # Make P1 output
	GPIO.setup(SRCLK, GPIO.OUT) # Make P2 output
	GPIO.setup(TouchPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)

	GPIO.output(SDI, 0)
	GPIO.output(RCLK, 0)
	GPIO.output(SRCLK, 0)

	GPIO.add_event_detect(TouchPin, GPIO.FALLING, callback=randomISR)

	print ""
	print ""
	print "========================================"
	print "|               Dice                   |"
	print "|    ------------------------------    |"
	print "|        SDI connect to GPIO0          |"
	print "|        RCLK connect to GPIO1         |"
	print "|       SRCLK connect to GPIO 2        |"
	print "|     Button Pin connect to GPIO 3     |"
	print "|                                      |"
	print "|     Control segment with 74HC595     |"
	print "|           random number 0~6          |"
	print "|    Press to supend segment 2 second  |"
	print "|                                      |"
	print "|                            SunFounder|"
	print "========================================"
	print ""
	print ""

def hc595_shift(dat):
	for bit in range(0, 8):	
		GPIO.output(SDI, 0x80 & (dat << bit))
		GPIO.output(SRCLK, GPIO.HIGH)
		time.sleep(0.001)
		GPIO.output(SRCLK, GPIO.LOW)
	GPIO.output(RCLK, GPIO.HIGH)
	time.sleep(0.001)
	GPIO.output(RCLK, GPIO.LOW)

def randomISR(chn):
	global flag
	flag = 1

def main():
	global flag
	while True:
		num = random.randint(0, 5)
		hc595_shift(SegCode[num])
		if flag == 1:
			print "Pressed when %d on Segment\n" % (num+1)
			time.sleep(2)
			flag = 0
		else:
			time.sleep(0.06)

def destroy():
	GPIO.cleanup()

if __name__ == '__main__':
	try:
		setup()
		main()
	except KeyboardInterrupt:
		destroy()