DEBUG	= -O3
CC	= gcc
INCLUDE	= -I/usr/local/include
CFLAGS	= $(DEBUG) -Wall $(INCLUDE) -Winline -pipe

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
		07_motor.c				\
		08_rotaryEncoder.c		\
		09_74HC595_LED.c		\
		10_segment.c            \
		11_dotMatrix.c 		    \
		12_lcd1602.c			\
		13_adxl345.c			
			
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
	
07_motor:	07_motor.o
	@echo [link]
	@$(CC) -o $@ 07_motor.o $(LDFLAGS) $(LDLIBS)
	
08_rotaryEncoder:	08_rotaryEncoder.o
	@echo [link]
	@$(CC) -o $@ 08_rotaryEncoder.o $(LDFLAGS) $(LDLIBS)
	
09_74HC595_LED:	09_74HC595_LED.o
	@echo [link]
	@$(CC) -o $@ 09_74HC595_LED.o $(LDFLAGS) $(LDLIBS)

10_segment:	10_segment.o
	@echo [link]
	@$(CC) -o $@ 10_segment.o $(LDFLAGS) $(LDLIBS)

11_dotMatrix:	11_dotMatrix.o
	@echo [link]
	@$(CC) -o $@ 11_dotMatrix.o $(LDFLAGS) $(LDLIBS)

12_lcd1602:	12_lcd1602.o
	@echo [link]
	@$(CC) -o $@ 12_lcd1602.o $(LDFLAGS) $(LDLIBS)

13_adxl345:	13_adxl345.o
	@echo [link]
	@$(CC) -o $@ 13_adxl345.o $(LDFLAGS) $(LDLIBS)

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
