SRC=src/
OUT=out/

TARGET=$(OUT)snake
PREOBJS=snake.o progmem.o
OBJS=$(foreach V,$(PREOBJS),$(OUT)$(V))
MCU=atmega88p
PROG=usbasp

CC = avr-gcc
AS = avr-as
LD = avr-ld
OC = avr-objcopy
AD = avrdude

CCF += -g -mmcu=$(MCU)
CCF += -Os
ASF += -g -mmcu=$(MCU)

OCF += -j .text 
OCF += -j .data 
OCF += -O ihex

ADF += -p $(MCU)
ADF += -c $(PROG)
ADF += -B 20

.PHONY: all
all: $(TARGET).hex

$(TARGET).hex: $(TARGET).elf 
	$(OC) $(OCF) $< $@ 

$(TARGET).elf: $(OBJS)
	$(CC) $(CCF) -o $@ $^

$(OUT)%.o: $(SRC)%.s
	$(AS) $(ASF) -c -o $@ $<

$(OUT)%.o: $(SRC)%.c
	$(CC) $(CCF) -c -o $@ $<

.PHONY: upload
upload: $(TARGET).hex
	$(AD) $(ADF) -U flash:w:$<:i


.PHONY: clean
clean:
	rm $(OBJS)
	rm $(TARGET).hex
	rm $(TARGET).elf
