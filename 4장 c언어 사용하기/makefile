CC = gcc

final.img : boot.img sector2.img disk.img
	cat boot.img sector2.img disk.img > final.img

disk.img : main.img
	objcopy -O binary main.img disk.img

main.img : main.o
	ld -melfi386 -Ttext 0x10200 -nostdlib main.o -o main.img

main.o : main.c
	gcc -c -m32 -ffreestanding main.c -o main.o

boot.img : boot.asm
	nasm -f bin -o boot.img boot.asm

sector2.img : sector2.asm
	nasm -f bin -o sector2.img sector2.asm

clean :
	rm *.o

