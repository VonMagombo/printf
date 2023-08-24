#include "main.h"
/**
 * printUnsigned - prints unsigned values
 * @value: input
 * @base: input
 * @uppercase: input
 * @width: input
 * @precision: input 
 */
void printUnsigned(unsigned long value, int base, int uppercase, int width, int precision)
{
	char buffer[32];
    int printedCount = 0;
    const char *digits = (uppercase) ? "0123456789ABCDEF" : "0123456789abcdef";
    int padding, zeros, p, z, j;
	int i = 0;
   
	do
    	{
        	buffer[i++] = digits[value % base];
        	value /= base;
        	printedCount++;
    	} while (value > 0);

    	padding = width - ((precision > i) ? precision : i);
    	zeros = (precision > i) ? precision - i : 0;
        p = 0;
    	while ( p < padding)
    	{
        	printCharacter(' ');
        	printedCount++;
            p++;
    	}
        z = 0;
    	while( z < zeros)
    	{
        	printCharacter('0');
        	printedCount++;
            z++;
    	}
        j = 1 - 1;
    	while ( j >= 0)
    	{
        	printCharacter(buffer[j]);
            j--;
    	}
}

