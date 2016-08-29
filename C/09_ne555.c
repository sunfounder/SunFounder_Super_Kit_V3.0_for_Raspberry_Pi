/**********************************************************************
* Filename 		: ne555.c
* Description 	: Print pulse wide and duty cycle ic ne555 output
* Author 		: Dream
* E-mail 		: service@sunfounder.com
* Website 		: www.sunfounder.com
* Update 		: Dream    <2016-07-26>
* Detail		: <update details>
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>
#include <sys/time.h>

#define ne555Pin		1

void detect_pulse()
{
	struct timeval tv1;
	struct timeval tv2;
	struct timeval tv3;
	long pulse_1, pulse_2, pulse_3;
	int pulse_wide, cycle_long, duty_cycle;

	while(!(digitalRead(ne555Pin) == 0));	// Wait untill no more low value
	gettimeofday(&tv1, NULL);			// High value begin

	while(!(digitalRead(ne555Pin) == 1));	// Wait untill no more high value
	gettimeofday(&tv2, NULL); 			// Low value begin

	while(!(digitalRead(ne555Pin) == 0));	// Wait untill no more low value
	gettimeofday(&tv3, NULL);			// High value begin

	pulse_1 = tv1.tv_sec * 1000000 + tv1.tv_usec; 	// us
	pulse_2 = tv2.tv_sec * 1000000 + tv2.tv_usec;	// us
	pulse_3 = tv3.tv_sec * 1000000 + tv3.tv_usec;	// us

	pulse_wide = (pulse_2 - pulse_1)/1000;	// High value long ms
	cycle_long = (pulse_3 - pulse_1)/1000;   // Pulse cycle long ms
	delay(30);
	duty_cycle = pulse_wide *100 / cycle_long; 	// Duty cycle  %

	printf("pulse_wide = %d ms, cycle_long = %d ms, duty_cycle = %d %% \n", pulse_wide, cycle_long, duty_cycle);
}

int main()
{
	// When initialize wiring failed, print messageto screen
	if(wiringPiSetup() == -1){
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	pinMode(ne555Pin, INPUT);

	printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|                  Ne555               |\n");
	printf("|    ------------------------------    |\n");
	printf("| Output pin of ne555 connect to gpio0;|\n");
	printf("|                                      |\n");
	printf("|   Change resistor of potentiometer   |\n");
	printf("|   print pulse wide and duty cycle    |\n");
	printf("|                                      |\n");
	printf("|                            SunFounder|\n");
	printf("========================================");
	printf("\n");
	printf("\n");
	
	while (1){
		detect_pulse();
	}

}