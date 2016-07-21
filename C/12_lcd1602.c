/**********************************************************************
* Filename    : lcd1602.c
* Description : Use lcd1602.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Update      : Cavon    2016/07/01
**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <lcd.h>

const unsigned char Buf[] = "---SUNFOUNDER---";
const unsigned char myBuf[] = "  sunfounder.com";

int main(void)
{
	int fd;
	int i;
	
	if(wiringPiSetup() == -1){
		exit(1);
	}
	
	fd = lcdInit(2,16,4, 2,3, 6,5,4,1,0,0,0,0); //see /usr/local/include/lcd.h
	printf("%d", fd);
	if (fd == -1){
		printf("lcdInit 1 failed\n") ;
		return 1;
	}
	sleep(1);
	lcdClear(fd);
	lcdPosition(fd, 0, 0); 
	lcdPuts(fd, "Welcome To--->");

	lcdPosition(fd, 0, 1); 
	lcdPuts(fd, "  sunfounder.com");

	sleep(1);
	lcdClear(fd);
	
	printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|                LCD1602               |\n");
	printf("|    ------------------------------    |\n");
	printf("|         D4 connect to GPIO0          |\n");
	printf("|         D5 connect to GPIO1          |\n");
	printf("|         D6 connect to GPIO2          |\n");
	printf("|         D7 connect to GPIO3          |\n");
	printf("|         RS connect to GPIO15         |\n");
	printf("|         RW connect to GND            |\n");
	printf("|         CE connect to GPIO16         |\n");
	printf("|                                      |\n");
	printf("|           Control LCD1602            |\n");
	printf("|                                      |\n");
	printf("|                            SunFounder|\n");
	printf("========================================\n");
	printf("\n");
	printf("\n");

	while(1){
		lcdClear(fd);
		for(i=0; i<16; i++){
			lcdPosition(fd, i, 0);
			lcdPutchar(fd, *(myBuf+i));
			delay(100);
		}
		for(i=0;i<sizeof(Buf)-1;i++){
			lcdPosition(fd, i, 1);
			lcdPutchar(fd, *(Buf+i));
			delay(200);
		}
		sleep(0.5);
	}
	return 0;
}
