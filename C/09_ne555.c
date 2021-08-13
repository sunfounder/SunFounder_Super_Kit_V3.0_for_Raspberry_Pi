/**********************************************************************
* Filename 		: ne555.c
/**********************************************************************
* Filename 		: ne555.c
* Description 	: Count the pluses procude by NE555.
* Author 		: Robot
* E-mail 		: support@sunfounder.com
* Website 		: www.sunfounder.com
* Update 		: Dream    <2016-07-26>
* Detail		: <update details>
**********************************************************************/
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPi.h>

#define  Pin0  1

static volatile int globalCounter = 0 ;

void exInt0_ISR(void)  //GPIO0 interrupt service routine 
{
	++globalCounter;
}

int main (void)
{
  if(wiringPiSetup() < 0){
  	fprintf(stderr, "Unable to setup wiringPi:%s\n",strerror(errno));
	return 1;
  }

	printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|                  Ne555               |\n");
	printf("|    ------------------------------    |\n");
	printf("| Output pin of ne555 connect to gpio1;|\n");
	printf("|                                      |\n");
	printf("|  Count the pulses procude by NE555.  |\n");
	printf("|                                      |\n");
	printf("|                            SunFounder|\n");
	printf("========================================");
	printf("\n");
	printf("\n");
	
	delay(2000);  
  pinMode(Pin0,INPUT);
  pullUpDnControl(Pin0,PUD_UP);
  wiringPiISR(Pin0, INT_EDGE_FALLING, &exInt0_ISR);
  
   while(1){
	   
	   printf("Current pluse number is : %d, %d\n", globalCounter,digitalRead(Pin0));
	   delay(100);
    }

  return 0;
}
