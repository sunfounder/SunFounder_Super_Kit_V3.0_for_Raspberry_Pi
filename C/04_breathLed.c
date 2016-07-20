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

#define LedPin    1

int main(void)
{
	int i;

	if(wiringPiSetup() == -1){ //when initialize wiring failed, printf messageto screen
		printf("setup wiringPi failed!\n");
		return 1; 
	}
	
	pinMode(LedPin, PWM_OUTPUT);//pwm output mode

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
		for(i=0;i<1024;i++){
			pwmWrite(LedPin, i);
			delay(2);
		}
		delay(1000);
		printf("Breath off\n");
		for(i=1023;i>=0;i--){
			pwmWrite(LedPin, i);
			delay(2);
		}
	}

	return 0;
}

