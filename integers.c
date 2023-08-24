#include "main.h"
/**
 * printInteger: handles integers
 * @param value
 * @param flags
 * @param width
 * @param precision
 * Return: int
 */
int printInteger(long value, int flags, int width, int precision)
{
	char buffer[32];
    	int printedCount = 0;
	int i = 0;
	int z, j, p;
	int padding, zeros;

    	if (value < 0)
    	{
        	printCharacter('-');
        	printedCount++;
        	value = -value;
    	}
    	else if (flags & 0x02) 
    	{
        	printCharacter('+');
        	printedCount++;
    	}
    	else if (flags & 0x04) 
    	{
        	printCharacter(' ');
        	printedCount++;
    	}
    	do
    	{
        	buffer[i++] = '0' + (value % 10);
        	value /= 10;
        	printedCount++;
    	} while (value > 0);
    	padding = width - i;
    	zeros = (precision > i) ? precision - i : 0;
    	for (p = 0; p < padding; p++)
    	{
        	printCharacter(' ');
        	printedCount++;
    	}
    	for (z = 0; z < zeros; z++)
    	{
        	printCharacter('0');
        	printedCount++;
    	}
    	for (j = i - 1; j >= 0; j--)
    	{
        	printCharacter(buffer[j]);
    	}

    	return (printedCount);
}
