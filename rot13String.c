#include "main.h"
/**
 * printRot13String - prints rot13 string
 * @str: input 
 */
void printRot13String(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
        {
		char ch = str[i];
        	if (ch >= 'A' && ch <= 'Z')
        	{
            		ch = 'A' + (ch - 'A' + 13) % 26;
        	}
        	else if (ch >= 'a' && ch <= 'z')
        	{
            		ch = 'a' + (ch - 'a' + 13) % 26;
        	}
        	printCharacter(ch);
    	}
}

