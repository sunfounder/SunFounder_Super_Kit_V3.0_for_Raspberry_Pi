/**********************************************************************
* Filename    : rgbLed.c
* Description : Make a RGB LED emits various color.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Update      : Cavon    2016/07/01
**********************************************************************/
#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

#define uchar unsigned char

#define LedPinRed    0
#define LedPinGreen  1
#define LedPinBlue   2

void ledInit(void){
	softPwmCreate(LedPinRed,  0, 100);
	softPwmCreate(LedPinGreen,0, 100);
	softPwmCreate(LedPinBlue, 0, 100);
}

void ledColorSet(uchar r_val, uchar g_val, uchar b_val){
	softPwmWrite(LedPinRed,   r_val);
	softPwmWrite(LedPinGreen, g_val);
	softPwmWrite(LedPinBlue,  b_val);
}

int main(void){

	if(wiringPiSetup() == -1){ //when initialize wiring failed, printf messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}

	ledInit();

	printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|              Breath LED              |\n");
	printf("|    ------------------------------    |\n");
	printf("|       Red Pin connect to GPIO0       |\n");
	printf("|      Green Pin connect to GPIO1      |\n");
	printf("|       Blue Pin connect to GPIO2      |\n");
	printf("|                                      |\n");
	printf("|  Make a RGB LED emits various color  |\n");
	printf("|                                      |\n");
	printf("|                            SunFounder|\n");
	printf("========================================\n");
	printf("\n");
	printf("\n");

	while(1){
		printf("Red\n");
		ledColorSet(0xff,0x00,0x00);   //red	
		delay(500);
		printf("Green\n");
		ledColorSet(0x00,0xff,0x00);   //green
		delay(500);
		printf("Blue\n");
		ledColorSet(0x00,0x00,0xff);   //blue
		delay(500);

		printf("Yellow\n");
		ledColorSet(0xff,0xff,0x00);   //yellow
		delay(500);
		printf("Purple\n");
		ledColorSet(0xff,0x00,0xff);   //purple
		delay(500);
		printf("Cyan\n");
		ledColorSet(0xc0,0xff,0x3e);   //cyan
		delay(500);
	}

	return 0;
}
