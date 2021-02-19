all:
	avr-gcc -DF_CPU=1200000UL -Os -mmcu=attiny13 electricBonsai.c -o electricBonsai.elf
	avr-objcopy -j .text -j .data -O ihex electricBonsai.elf electricBonsai.hex
	avrdude -B 5 -p t13  -c avrispmkII -P usb -U flash:w:electricBonsai.hex
