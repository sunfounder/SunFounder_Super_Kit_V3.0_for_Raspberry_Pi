/**********************************************************************
* Filename    : buttonControlLed.c
* Description : Controlling an led with button.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Update      : Cavon    2016/07/01
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>

#define LedPin		0
#define ButtonPin 	1

int main(void){
	// When initialize wiring failed, print messageto screen
	if(wiringPiSetup() == -1){
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	pinMode(LedPin, OUTPUT); 
	pinMode(ButtonPin, INPUT);
	// Pull up to 3.3V,make GPIO1 a stable level
	pullUpDnControl(ButtonPin, PUD_UP);

	printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|          Button control LED          |\n");
	printf("|    ------------------------------    |\n");
	printf("|         LED connect to GPIO0         |\n");
	printf("|        Button connect to GPIO1       |\n");
	printf("|                                      |\n");
	printf("|     Press button to turn on LED.     |\n");
	printf("|                                      |\n");
	printf("|                            SunFounder|\n");
	printf("========================================\n");
	printf("\n");
	printf("\n");

	digitalWrite(LedPin, HIGH);
	printf("LED off...\n");

	while(1){
		// Indicate that button has pressed down
		if(digitalRead(ButtonPin) == 0){
			// Led on
			digitalWrite(LedPin, LOW);
			printf("...LED on\n");
			delay(100);
		}
		else{
			// Led off
			digitalWrite(LedPin, HIGH);
			printf("LED off...\n");
			delay(100);
		}
	}
	return 0;
}

