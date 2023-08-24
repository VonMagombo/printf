#include "main.h"
/**
 * printCharacter - prints character 
 * @ch: input 
 */
void printCharacter(char ch)
{
    putchar(ch);
}

/**
 * printString - prints a string 
 * @str: string to be printed 
 * Return: void
 */

void printString(const char *str)
{
	int i= 0;

	while (str[i] != '\0')
	{
		printCharacter(str[i]);
		i++;
        }
}
