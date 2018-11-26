# LED-parallel-port
Power ON/OFF LEDs using the parallel port in C

The point of this code is to use the parallel port to light up LEDs that are connected to it.
You can read more here: https://wndlpt.sourceforge.io/lpt/
You can read more about parallel ports here: https://en.wikipedia.org/wiki/Parallel_port

User interface is added in v9, where you can choose options from [1-6] and [0] for exit:
1. Binary number (there is a converter added that shows you the number in decimal)
2. Decimal number
3. Numbers from [1-8]
4. Use current configuration [1458] (of course you can set your own configuration, current one is 1458)
5. Turn ON all the LEDs
6. Turn OFF all the LEDs
0. Exit

However during the while(1) statements if you press any symbol different than a number, you can assume what will happen.
