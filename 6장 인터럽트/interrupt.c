#include "interrupt.h"
#include "function.h"

struct IDT inttable[3] ;
struct IDTR idtr = { 256 * 8 - 1, 0 } ;

void init_intdesc() {

    int i, j ;
    unsigned int ptr ;
    unsigned short *isr ;

    {
        ptr = (unsigned int)idt_ignore ;
        inttable[0].selector = (unsigned short)0x08 ;
        inttable[0].type = (unsigned short)0x8E00 ;
        inttable[0].offsetl = (unsigned short)(ptr & 0xFFFF) ;
        inttable[0].offseth = (unsigned short)(ptr >> 16) ;
    }

    {  
		ptr = (unsigned int)idt_timer;
		inttable[1].selector = (unsigned short)0x08;
		inttable[1].type = (unsigned short)0x8E00;
		inttable[1].offsetl = (unsigned short)(ptr & 0xFFFF);
		inttable[1].offseth = (unsigned short)(ptr >> 16);

	}

	{  
		ptr = (unsigned int)idt_keyboard;
		inttable[2].selector = (unsigned short)0x08;
		inttable[2].type = (unsigned short)0x8E00;
		inttable[2].offsetl = (unsigned short)(ptr & 0xFFFF);
		inttable[2].offseth = (unsigned short)(ptr >> 16);

	}

    for (i = 0; i < 256; i++)
	{
		isr = (unsigned short*)(0x0 + i * 8);
		*isr = inttable[0].offsetl;
		*(isr + 1) = inttable[0].selector;
		*(isr + 2) = inttable[0].type;
		*(isr + 3) = inttable[0].offseth;

	}

	// 타이머 ISR 등록
	{
		isr = (unsigned short*)(0x0 + 8 * 0x20);
		*isr = inttable[1].offsetl;
		*(isr + 1) = inttable[1].selector;
		*(isr + 2) = inttable[1].type;
		*(isr + 3) = inttable[1].offseth;
	}

	// 키보드 ISR 등록
	{
		isr = (unsigned short*)(0x0 + 8 * 0x21);
		*isr = inttable[2].offsetl;
		*(isr + 1) = inttable[2].selector;
		*(isr + 2) = inttable[2].type;
		*(isr + 3) = inttable[2].offseth;
	
	}

    __asm__ __volatile__("mov eax, %0"::"r"(&idtr));
	__asm__ __volatile__("lidt [eax]");
	__asm__ __volatile__("mov al,0xFC");
	__asm__ __volatile__("out 0x21,al");
	__asm__ __volatile__("sti");

	return;
}
void idt_ignore() {} 
void idt_timer() {}
void idt_keyboard() {}


