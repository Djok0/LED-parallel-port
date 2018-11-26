#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>
#define DATA 0x378
#define LED 0x99

int main(void) {
	if (ioperm(DATA,3,1)) exit(0);
	else outb(LED,DATA);
} 
