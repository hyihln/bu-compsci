
all: prelim ret2libc

prelim:	prelim.c
	gcc -m32 prelim.c -o prelim

ret2libc: ret2libc.c get_ebp.S
	gcc -m32 ret2libc.c get_ebp.S -o ret2libc

clean:
	rm prelim ret2libc
