#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>


#define DATA 0x378

int checkAccess();
int menu();
int binaryToDecimal();
int decimalNumber();
int userChoice();
int turnOnConfiguration();
int turnOn();
int turnOff();

int main(void)
{
	checkAccess();
} 

int checkAccess()
{
	if (ioperm(DATA,3,1))
	{ 
		printf("You have no access to the parallel port!\n");
 		printf("Use either root or use SUDO to run\n");
 		exit(0);
 	}
	else menu();
}

int menu()
{
	int choice;
	while(1)
	{
		printf("--------------Menu--------------\n");
		printf("|Choose how to light up the LED|\n");
		printf("|1. Use Binary number          |\n");
		printf("|2. Use Decimal number         |\n");
		printf("|3. Use [1-8]                  |\n");
		printf("|4. Turn LED ON config [1458]  |\n");
		printf("|5. Turn ALL LED ON            |\n");
		printf("|6. Turn LED OFF               |\n");
		printf("|0. Exit                       |\n");
		printf("--------------------------------\n");
		printf("Enter your choise: [1-6] or [0] to exit: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 0: printf("Bye!\n");
				exit(0);
			break;

			case 1: binaryToDecimal();
			break;

			case 2: decimalNumber();
			break;

			case 3: userChoice();
			break;

			case 4: turnOnConfiguration();
			break;

			case 5: turnOn();
			break;

			case 6: turnOff();
			break;

			default: printf("You must choose from options [1-6] or [0] to exit\n");
			break;
		}
	}
}

int binaryToDecimal()
{
	int num, binary_val, decimal_val = 0, base = 1, rem;
	int LED;
	printf("Enter a BINARY number: ");
	scanf("%d", &num);
	binary_val = num;
	while (num > 0)
	{
		rem = num % 10;
		decimal_val = decimal_val + rem * base;
		num = num / 10;
		base = base * 2;
	}
	printf("The BINARY number you entered is = %d \n", binary_val);
	printf("The number converted to DECIMAL is = %d \n", decimal_val);
	LED = decimal_val;
	outb(LED,DATA);
}

int decimalNumber()
{
	int x;
	printf("Enter a DECIMAL number: ");
	scanf("%d", &x);
	outb(x,DATA);
}

int userChoice() 
{
	int x;
	unsigned char LED;
	while(1)
	{
		printf("Please enter LED number [1-8] or press [0] to return to Menu: ");
		scanf("%d", &x);
		printf("\n");
		if (x == 0)
			main();
		else if (x < 0 || x > 8)
			printf("You entered invalid number.\n");
		else
		{
			LED = LED ^ (1u << (x - 1));
			outb(LED,DATA);
		}
	}
}

int turnOnConfiguration()
{
	outb(0x99,DATA);
	printf("You turned ON the configuration [1458]\n");	
}

int turnOn()
{
	outb(255,DATA);
	printf("You turned ON all the LEDs\n");
}

int turnOff()
{
	outb(0,DATA);
	printf("You turned OFF the LED\n");
}
