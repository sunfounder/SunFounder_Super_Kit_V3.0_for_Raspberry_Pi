/**********************************************************************
* Filename    : rotaryEncoder.c
* Description : Use a Rotary Encoder.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Update      : Cavon    2016/07/01
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#define   SDI   0   //serial data input
#define   RCLK  1   //memory clock input(STCP)
#define   SRCLK 2   //shift register clock input(SHCP)

#define   TouchPin  3

unsigned char SegCode[6] = {0x06,0x5b,0x4f,0x66,0x6d,0x7d};

unsigned char flag = 0;

void init(void)
{
	pinMode(SDI, OUTPUT); //make P0 output
	pinMode(RCLK, OUTPUT); //make P1 output
	pinMode(SRCLK, OUTPUT); //make P2 output
	pinMode(TouchPin, INPUT);
	pullUpDnControl(TouchPin, PUD_UP);

	digitalWrite(SDI, 0);
	digitalWrite(RCLK, 0);
	digitalWrite(SRCLK, 0);
}

void hc595_shift(unsigned char dat)
{
	int i;

	for(i=0;i<8;i++){
		digitalWrite(SDI, 0x80 & (dat << i));
		digitalWrite(SRCLK, 1);
		delay(1);
		digitalWrite(SRCLK, 0);
	}

		digitalWrite(RCLK, 1);
		delay(1);
		digitalWrite(RCLK, 0);
}

void randomISR(void)
{
	flag = 1;
}

int main(void)
{
	int num;

	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}

	init();

	printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|               Dice                   |\n");
	printf("|    ------------------------------    |\n");
	printf("|        SDI connect to GPIO0          |\n");
	printf("|        RCLK connect to GPIO1         |\n");
	printf("|       SRCLK connect to GPIO 2        |\n");
	printf("|     Button Pin connect to GPIO 3     |\n");
	printf("|                                      |\n");
	printf("|     Control segment with 74HC595     |\n");
	printf("|           random number 0~6          |\n");
	printf("|    Press to supend segment 2 second  |\n");
	printf("|                                      |\n");
	printf("|                            SunFounder|\n");
	printf("========================================\n");
	printf("\n");
	printf("\n");

	if(wiringPiISR(TouchPin, INT_EDGE_FALLING, &randomISR)){
		printf("Unable to setup ISR : %s\n", strerror(errno));	
		return 1;
	}

	srand(time(NULL));
	
	while(1){
		num = rand() % 6;
		hc595_shift(SegCode[num]);
		if(flag == 1){
			printf("flag = %d, ",flag);
			printf("Pressed when %d on Segment\n", (num+1));
			delay(2000);
			flag = 0;
		}
		else{	
			delay(60);
		}
		
	}

	return 0;
}

