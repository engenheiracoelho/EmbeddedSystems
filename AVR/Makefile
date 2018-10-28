PRG = EX02
PORT = /dev/ttyUSB0
TARGET_HW = atmega2560
CC = avr-g++
OBJCOPY = avr-objcopy
PRGFLASH = avrdude

DEFS =
LIBS =
OPTIMIZE = -O2
CFLAGS = -g -Wall $(OPTIMIZE) -mmcu=$(TARGET_HW) $(DEFS)

all: $(PRG).hex clean

$(PRG).o:
	$(CC) $(CFLAGS) -c $(PRG).cpp

$(PRG).elf: $(PRG).o
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(PRG).hex: $(PRG).elf
	$(OBJCOPY) -j .text -j .data -O ihex $(PRG).elf $(PRG).hex

clean:
	rm *.o *.elf

clear:
	rm *.o *.elf *.hex

flash:
	$(PRGFLASH) -p $(TARGET_HW) -c wiring -P $(PORT) -D -U flash:w:$(PRG).hex:i