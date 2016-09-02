DEBUG	= -O3
CC	= gcc

INCLUDE	= -I/usr/local/include
CFLAGS	= $(DEBUG) -w $(INCLUDE) -Winline -pipe
LDFLAGS	= -L/usr/local/lib
LDLIBS    = -lwiringPi -lwiringPiDev -lpthread -lm

# Should not alter anything below this line
###############################################################################
SRC	=	01_blinkLed.c			\
        02_buttonControlLed.c	\
		03_8Led.c				\
		04_breathLed.c			\
		05_rgb.c				\
		06_beep.c				\
		07_relay.c				\
		08_4N35.c				\
		09_ne555.c				\
		10_slideSwitch.c		\
		11_motor.c				\
		12_rotaryEncoder.c		\
		13_74HC595_LED.c		\
		14_segment.c            \
		14_dice.c				\
		15_dotMatrix.c 		    \
		16_lcd1602.c			\
		17_adxl345.c

OBJ		=	$(SRC:.c=.o)
BINS	=	$(SRC:.c=)

#all:
#	@cat README.md
#	@echo "    $(BINS)" | fmt
#	@echo ""

all:	$(BINS)

01_blinkLed:	01_blinkLed.o
	@echo [link]
	@$(CC) -o $@ 01_blinkLed.o $(LDFLAGS) $(LDLIBS)

02_buttonControlLed:	02_buttonControlLed.o
	@echo [link]
	@$(CC) -o $@ 02_buttonControlLed.o $(LDFLAGS) $(LDLIBS)

03_8Led:	03_8Led.o
	@echo [link]
	@$(CC) -o $@ 03_8Led.o $(LDFLAGS) $(LDLIBS)

04_breathLed:	04_breathLed.o
	@echo [link]
	@$(CC) -o $@ 04_breathLed.o $(LDFLAGS) $(LDLIBS)

05_rgb:	05_rgb.o
	@echo [link]
	@$(CC) -o $@ 05_rgb.o $(LDFLAGS) $(LDLIBS)

06_beep:	06_beep.o
	@echo [link]
	@$(CC) -o $@ 06_beep.o $(LDFLAGS) $(LDLIBS)

07_relay:	07_relay.o
	@echo [link]
	@$(CC) -o $@ 07_relay.o $(LDFLAGS) $(LDLIBS)

08_4N35:	08_4N35.o
	@echo [link]
	@$(CC) -o $@ 08_4N35.o $(LDFLAGS) $(LDLIBS)

09_ne555:	09_ne555.o
	@echo [link]
	@$(CC) -o $@ 09_ne555.o $(LDFLAGS) $(LDLIBS)

10_slideSwitch:	10_slideSwitch.o
	@echo [link]
	@$(CC) -o $@ 10_slideSwitch.o $(LDFLAGS) $(LDLIBS)

11_motor:	11_motor.o
	@echo [link]
	@$(CC) -o $@ 11_motor.o $(LDFLAGS) $(LDLIBS)

12_rotaryEncoder:	12_rotaryEncoder.o
	@echo [link]
	@$(CC) -o $@ 12_rotaryEncoder.o $(LDFLAGS) $(LDLIBS)

13_74HC595_LED:	13_74HC595_LED.o
	@echo [link]
	@$(CC) -o $@ 13_74HC595_LED.o $(LDFLAGS) $(LDLIBS)

14_segment:	14_segment.o
	@echo [link]
	@$(CC) -o $@ 14_segment.o $(LDFLAGS) $(LDLIBS)

14_dice: 14_dice.o
	@echo [link]
	@$(CC) -o $@ 14_dice.o $(LDFLAGS) $(LDLIBS)

15_dotMatrix:	15_dotMatrix.o
	@echo [link]
	@$(CC) -o $@ 15_dotMatrix.o $(LDFLAGS) $(LDLIBS)

16_lcd1602:	16_lcd1602.o
	@echo [link]
	@$(CC) -o $@ 16_lcd1602.o $(LDFLAGS) $(LDLIBS)

17_adxl345:	17_adxl345.o
	@echo [link]
	@$(CC) -o $@ 17_adxl345.o $(LDFLAGS) $(LDLIBS)

.c.o:
	@echo [CC] $<
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@echo "[Clean]"
	@rm -f $(OBJ) *~ core tags $(BINS)

tags:	$(SRC)
	@echo [ctags]
	@ctags $(SRC)

depend:
	makedepend -Y $(SRC)

# DO NOT DELETE
