#include "main.h"
/**
 * printBuffer - prints buffer contents
 * @buffer: array for buffer.
 * @bufferIndex: index
 * 
 */
void printBuffer(char buffer[], int *bufferIndex)
{
    int i = 0;
    if (*bufferIndex > 0)
    {
        while( i < *bufferIndex)
        {
            printCharacter(buffer[i]);
            i++;
        }
    }

    *bufferIndex = 0;
}
/**
 * printSpecialString - prints special string
 * @str: input
 */
void printSpecialString(const char *str)
{
    int i= 0;
    while ( str[i] != '\0')
    {
        if (str[i] < ' ' || str[i] >= 127)
        {
            printCharacter('\\');
            printCharacter('x');
            printUnsigned((unsigned char)str[i], 16, 1, 0, 0);
        }
        else
        {
            printCharacter(str[i]);
        }
        i++;
    }
}