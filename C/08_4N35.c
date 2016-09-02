/**********************************************************************
* Filename 		: 4N35.c
* Description 	: Make a 4N35 to contral led blinking
* Author 		: Dream
* E-mail 		: support@sunfounder.com
* Website 		: www.sunfounder.com
* Update 		: Dream    <2016-07-26>
* Detail		: <update details>
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>

#define _4N35Pin		0

int main(void)
{
	// When initialize wiring failed, print messageto screen
	if(wiringPiSetup() == -1){
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	pinMode(_4N35Pin, OUTPUT);

	printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|                 4N35                 |\n");
	printf("|    ------------------------------    |\n");
	printf("|      LED connect to 4N35 pin5;       |\n");
	printf("|      gpio0 connect to 4N35 pin2；    |\n");
	printf("|                                      |\n");
	printf("|     4N35 to contral led blinking.    |\n");
	printf("|                                      |\n");
	printf("|                            SunFounder|\n");
	printf("========================================");
	printf("\n");
	printf("\n");
	
	while(1){
		// LED on
		digitalWrite(_4N35Pin, LOW);
		printf("...LED on\n");
		delay(500);
		// LED off
		digitalWrite(_4N35Pin, HIGH);
		printf("LED off...\n");
		delay(500);
	}

	return 0;
}


