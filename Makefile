DEVICE=attiny85

CC=avr-gcc
F_CPU   = 16000000	# in Hz
COMPILE = avr-gcc -Wall -Os -DF_CPU=$(F_CPU) $(CFLAGS) -mmcu=$(DEVICE)

all: blink

blink: upload-ledblinky

.c.o:
	$(COMPILE) -c $< -o $@

ledblinky.elf: ledblinky.o
	$(CC) -mmcu=$(DEVICE) -o ledblinky.elf ledblinky.o

ledblinky.hex: ledblinky.elf
	avr-objcopy -j .text -j .data -O ihex ledblinky.elf ledblinky.hex

upload-ledblinky: ledblinky.hex
	avrdude -P /dev/ttyUSB1 -c avrisp -p t85 -b 19200 -v -e -U flash:w:ledblinky.hex






