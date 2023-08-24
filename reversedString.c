#include "main.h"
/**
 * printReversedString - reverses a string
 * @str: input 
 */
void printReversedString(const char *str)
{
    int length = strlen(str);
    int i = length - 1;

    while(i >= 0)
    {
        printCharacter(str[i]);
        i--;
    }
}

