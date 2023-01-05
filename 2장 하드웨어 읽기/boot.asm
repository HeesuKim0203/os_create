[org 0]
[bits 16]

jmp 0x07C0:start

start:

mov ax, 0xB800
mov es, ax

mov byte[es:0], 'h'
mov byte[es:1], 0x09
mov byte[es:2], 'i'
mov byte[es:3], 0x09

read : 

	mov ax, 0x1000
	mov es, ax
	mov bx, 0
	
	mov ah, 2
	mov al, 1
	mov ch, 0
	mov cl, 2
	mov dh, 0
	mov dl, 0
	int 13h
	
	jc read

jmp 0x1000:0

times 510-($-$$) db 0
dw 0xAA55