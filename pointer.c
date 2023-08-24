#include "main.h"
/**
 * printPointer - prints value pointed
 * @ptr: pointer value 
 */
void printPointer(const void *ptr)
{
	printCharacter('0');
	printCharacter('x');
	printUnsigned((unsigned long)ptr, 16, 1, 0, 0);
}

