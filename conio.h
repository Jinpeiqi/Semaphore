/**
 * @file conio.h
 * Copyright 2012, 2013 MinGW.org project
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#ifndef	_CONIO_H_
#define	_CONIO_H_
#pragma GCC system_header
#include <_mingw.h>

/*
 * Low level console I/O functions. Pretty please try to use the ANSI
 * standard ones if you are writing new code.
 */

#ifndef RC_INVOKED

#ifdef	__cplusplus
extern "C" {
#endif

_CRTIMP char* __cdecl __MINGW_NOTHROW	_cgets (char*);
_CRTIMP int __cdecl __MINGW_NOTHROW	_cprintf (const char*, ...);
_CRTIMP int __cdecl __MINGW_NOTHROW	_cputs (const char*);
_CRTIMP int __cdecl __MINGW_NOTHROW	_cscanf (char*, ...);

_CRTIMP int __cdecl __MINGW_NOTHROW	_getch (void);
_CRTIMP int __cdecl __MINGW_NOTHROW	_getche (void);
_CRTIMP int __cdecl __MINGW_NOTHROW	_kbhit (void);
_CRTIMP int __cdecl __MINGW_NOTHROW	_putch (int);
_CRTIMP int __cdecl __MINGW_NOTHROW	_ungetch (int);

#define _NOCURSOR      0
#define _SOLIDCURSOR   1
#define _NORMALCURSOR  2
#ifndef _WINCON_H
typedef struct _COORD { short x;short y; } COORD;
typedef struct _CONSOLE_CURSOR_INFO { int dwSize; int bVisible; } CONSOLE_CURSOR_INFO,*PCONSOLE_CURSOR_INFO;
void * _stdcall GetStdHandle(long unsigned int);
int _stdcall SetConsoleCursorPosition(void *,_COORD);
int _stdcall SetConsoleCursorInfo(void *,const _CONSOLE_CURSOR_INFO *);
#endif
void gotoxy(int x,int y) { SetConsoleCursorPosition(GetStdHandle(0xfffffff5),(COORD){x,y}); }
void _setcursortype(int i) { CONSOLE_CURSOR_INFO c={100,i}; SetConsoleCursorInfo(GetStdHandle(0xfffffff5),&c);}
void clrscr() {int i;for(i=0;i<40;i++) puts("");gotoxy(0,0);}

#ifndef	_NO_OLDNAMES

_CRTIMP int __cdecl __MINGW_NOTHROW	getch (void);
_CRTIMP int __cdecl __MINGW_NOTHROW	getche (void);
_CRTIMP int __cdecl __MINGW_NOTHROW	kbhit (void);
_CRTIMP int __cdecl __MINGW_NOTHROW	putch (int);
_CRTIMP int __cdecl __MINGW_NOTHROW	ungetch (int);

#endif	/* Not _NO_OLDNAMES */


#ifdef	__cplusplus
}
#endif

#endif	/* Not RC_INVOKED */

#endif	/* Not _CONIO_H_ */
