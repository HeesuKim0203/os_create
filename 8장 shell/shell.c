#include "data.h"
#include "shell.h"
#include "function.h"

void sh_clear()
{
	kprintf_clear_all() ;
	curline = -1 ;
}

void sh_version()
{
	kprintf("Kim Heesu", ++curline, 0) ;
	kprintf("Copyright <c> 2023 DemoSoft. All rights reserved", ++curline, 0) ;
}

void sh_cheerup() 
{
	kprintf("Let's all cheer up.", ++curline, 0) ;
}