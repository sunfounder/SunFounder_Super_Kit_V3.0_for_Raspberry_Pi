
import RPi.GPIO as GPIO
import time

ne555 = 18

def setup():
	GPIO.setmode(GPIO.BCM)
	GPIO.setup(ne555, GPIO.IN)

def main():
	while True:
		pulse_1 = 0
		pulse_2 = 0
		pulse_3 = 0

		while GPIO.input(ne555)==0:		# High value begin
			pulse_1 = time.time()
		while GPIO.input(ne555)==1:		# High value end and low value begin
			pulse_2 = time.time()
		while GPIO.input(ne555)==0:		# Low value end
			pulse_3 = time.time()

		pulse_wide = (pulse_2 - pulse_1)*1000	# High value long ms
		cycle_long = (pulse_3 - pulse_1)*1000  # Pulse cycle long ms
		duty_cycle = pulse_wide *100 / cycle_long 	# Duty cycle

		print ("pulse_wide = %d ms, duty_cycle = %d %%"%(pulse_wide, duty_cycle))

if __name__ == '__main__':
	try:
		setup()
		main()
	except KeyboardInterrupt:
		GPIO.cleanup()
