/**********************************************************************
* Filename    : rotaryEncoder.c
* Description : Use a Rotary Encoder.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Update      : Cavon    2016/07/01
**********************************************************************/
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPi.h>

#define  RoAPin    0
#define  RoBPin    1
#define  SWPin     2

static volatile int globalCounter = 0 ;

unsigned char flag;
unsigned char Last_RoB_Status;
unsigned char Current_RoB_Status;

void btnISR(void){
	globalCounter = 0;
}

void rotaryDeal(void){
	Last_RoB_Status = digitalRead(RoBPin);

	while(!digitalRead(RoAPin)){
		Current_RoB_Status = digitalRead(RoBPin);
		flag = 1;
	}

	if(flag == 1){
		flag = 0;
		if((Last_RoB_Status == 0)&&(Current_RoB_Status == 1)){
			globalCounter ++;	
		}
		if((Last_RoB_Status == 1)&&(Current_RoB_Status == 0)){
			globalCounter --;
		}
	}
}

int main(void){

	if(wiringPiSetup() == -1){ //when initialize wiring failed, printf messageto screen
		printf("setup wiringPi failed!\n");
		return 1; 
	}

	pinMode(SWPin, INPUT);
	pinMode(RoAPin, INPUT);
	pinMode(RoBPin, INPUT);

	pullUpDnControl(SWPin, PUD_UP);

    if(wiringPiISR(SWPin, INT_EDGE_FALLING, &btnISR) < 0){
		printf("init ISR failed!\n");	
		return 1;
	}

	printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|            Rotary Encoder            |\n");
	printf("|    ------------------------------    |\n");
	printf("|        Pin A connect to GPIO0        |\n");
	printf("|        Pin B connect to GPIO1        |\n");
	printf("|     Button Pin connect to GPIO 2     |\n");
	printf("|                                      |\n");
	printf("|         Use a Rotary Encoder         |\n");
	printf("|     Rotary to add/minus counter      |\n");
	printf("|      Press to set counter to 0       |\n");
	printf("|                                      |\n");
	printf("|                            SunFounder|\n");
	printf("========================================\n");
	printf("\n");
	printf("\n");

	int tmp = 0;
	while(1){
		rotaryDeal();
		if (tmp != globalCounter){
			printf("Counter : %d\n",globalCounter);
			tmp = globalCounter;
		}
	}
	return 0;
}
