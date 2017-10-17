/**********************************************************************
* Filename    : breathLed.c
* Description : Make LED breath.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Update      : Cavon    2016/07/01
**********************************************************************/

#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>

#define LedPin    1

int main(void)
{
	int i;

	if(wiringPiSetup() == -1){ //when initialize wiring failed, print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}
	softPwmCreate(LedPin, 0, 100);

	printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|              Breath LED              |\n");
	printf("|    ------------------------------    |\n");
	printf("|         LED connect to GPIO0         |\n");
	printf("|                                      |\n");
	printf("|            Make LED breath           |\n");
	printf("|                                      |\n");
	printf("|                            SunFounder|\n");
	printf("========================================\n");
	printf("\n");
	printf("\n");

	while(1){
		printf("Breath on\n");
		for(i=0;i<=100;i++){
			softPwmWrite(LedPin, i);
			delay(20);
		}
		delay(1000);
		printf("Breath off\n");
		for(i=100;i>=0;i--){
			softPwmWrite(LedPin, i);
			delay(20);
		}
	}

	return 0;
}

