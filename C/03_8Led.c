/**********************************************************************
* Filename    : 8Led.c
* Description : Make a breathing led.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Update      : Cavon    2016/07/01
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>

// Turn LED(channel) on
void led_on(int channel){
	digitalWrite(channel, LOW);
}

// Turn LED(channel) off
void led_off(int channel){
	digitalWrite(channel, HIGH);
}

int main(void){
	int i;

    if(wiringPiSetup() == -1){ //when initialize wiring failed, printf messageto screen
		printf("setup wiringPi failed!\n");
		return 1; 
	}
	// Set 8 pins' modes to output
	for(i=0;i<8;i++){       
		pinMode(i, OUTPUT);
	}

	printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|                8 LEDs                |\n");
	printf("|    ------------------------------    |\n");
	printf("|         LED0 connect to GPIO0        |\n");
	printf("|         LED1 connect to GPIO1        |\n");
	printf("|         LED2 connect to GPIO2        |\n");
	printf("|         LED3 connect to GPIO3        |\n");
	printf("|         LED4 connect to GPIO4        |\n");
	printf("|         LED5 connect to GPIO5        |\n");
	printf("|         LED6 connect to GPIO6        |\n");
	printf("|         LED7 connect to GPIO7        |\n");
	printf("|                                      |\n");
	printf("|            Flow LED effect           |\n");
	printf("|                                      |\n");
	printf("|                            SunFounder|\n");
	printf("========================================\n");
	printf("\n");
	printf("\n");

	while(1){
		// Turn LED on from left to right
		printf("From left to right.\n");
		for(i=0;i<8;i++){
			led_on(i);
			delay(100);
			led_off(i);
		}
		// Turn LED off from right to left
		printf("From right to left.\n");
		for(i=8;i>=0;i--){
			led_on(i);
			delay(100);
			led_off(i);
		}
	}

	return 0;
}

