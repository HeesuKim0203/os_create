[org 0x10000]
[bits 16]

mov ax, 0xB800
mov es, ax

mov byte[es:4], 's'
mov byte[es:5], 0x09
mov byte[es:6], 'e'
mov byte[es:7], 0x09
mov byte[es:8], 'c'
mov byte[es:9], 0x08
mov byte[es:10], 't'
mov byte[es:11], 0x08
mov byte[es:12], 'o'
mov byte[es:13], 0x08
mov byte[es:14], 'r'
mov byte[es:15], 0x07




jmp $

times 512-($-$$) db 0
