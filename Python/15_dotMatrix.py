#!/usr/bin/env python3

import RPi.GPIO as GPIO
import time
from sys import version_info

if version_info.major == 3:
	raw_input = input

SDI   = 17
RCLK  = 18
SRCLK = 27

# we use BX matrix, ROW for anode, and COL for cathode
# ROW  ++++
code_H = [0x01,0xff,0x80,0xff,0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff]
# COL  ----
code_L = [0x00,0x7f,0x00,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f]

def print_msg():
    print ("========================================")
    print ("|      Dot matrix with two 74HC595     |")
    print ("|    ------------------------------    |")
    print ("|        SDI connect to GPIO 0         |")
    print ("|        RCLK connect to GPIO 1        |")
    print ("|        SRCLK connect to GPIO 2       |")
    print ("|                                      |")
    print ("|   Control Dot matrix with 74HC595    |")
    print ("|                                      |")
    print ("|                            SunFounder|")
    print ("========================================\n")
    print 'Program is running...'
    print 'Please press Ctrl+C to end the program...'
    raw_input ("Press Enter to begin\n")

def print_matrix(matrix):
    for i in xrange(0,len(matrix)):
        print matrix[i]

def get_matrix(row_buffer, col_buffer, max_row=8, max_col=8):
    matrix_msg = [[0 for i in range(max_row)] for i in range(max_col)]
    
    print "row_buffer = 0x%02x , col_buffer = 0x%02x"%(row_buffer, col_buffer)
    for row_num in xrange(0,8):         
        for col_num in xrange(0,8):
            #print (row_num, col_num), '-->', (((row_buffer >> row_num) & 0x01), ((col_buffer >> col_num) & 0x01))
            if (((row_buffer >> row_num) & 0x01) - ((col_buffer >> col_num) & 0x01)):
                matrix_msg[row_num][col_num] = 1
    print_matrix(matrix_msg)
    matrix_msg = [[0 for i in range(max_row)] for i in range(max_col)]

def setup():
    GPIO.setmode(GPIO.BCM)    # Number GPIOs by its BCM location
    GPIO.setup(SDI, GPIO.OUT)
    GPIO.setup(RCLK, GPIO.OUT)
    GPIO.setup(SRCLK, GPIO.OUT)
    GPIO.output(SDI, GPIO.LOW)
    GPIO.output(RCLK, GPIO.LOW)
    GPIO.output(SRCLK, GPIO.LOW)

# Shift the data to 74HC595
def hc595_shift(dat):
    for bit in range(0, 8): 
        GPIO.output(SDI, 0x80 & (dat << bit))
        GPIO.output(SRCLK, GPIO.HIGH)
        time.sleep(0.001)
        GPIO.output(SRCLK, GPIO.LOW)
    GPIO.output(RCLK, GPIO.HIGH)
    time.sleep(0.001)
    GPIO.output(RCLK, GPIO.LOW)

def main():
    print_msg()
    while True:
        for i in range(0, len(code_H)):
            hc595_shift(code_L[i])
            hc595_shift(code_H[i])
            get_matrix(code_L[i], code_H[i])
            time.sleep(0.1)

        for i in range(len(code_H)-1, -1, -1):
            hc595_shift(code_L[i])
            hc595_shift(code_H[i])
            get_matrix(code_L[i], code_H[i])
            time.sleep(0.1)

def destroy():
    GPIO.cleanup()

if __name__ == '__main__':
    setup()
    try:
        main()
    except KeyboardInterrupt:
        destroy()