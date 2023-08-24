#include "main.h"
/**
 * _printf - printf function
 * @format: handles args
 * Return: int
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printedCount = 0;
    int characterCount = 0;
    int bufferIndex = 0;
    char outputBuffer[BUFFER_SIZE];
    const char *currentChar = format;
    int flags = 0;
    int width = 0;
    int precision = -1;
    int ch;
    char *rot13_str, *str;
    unsigned long value;

    va_start(args, format);

    while ( *currentChar != '\0' )
    {
        if (*currentChar == '%')
        {
            currentChar++;
              if (*currentChar == '+')
            {
                flags |= 0x02;
                currentChar++;
            }
            else if (*currentChar == ' ')
            {
                flags |= 0x04;
                currentChar++;
            }
            if (*currentChar >= '0' && *currentChar <= '9')
            {
                width = 0;
                while (*currentChar >= '0' && *currentChar <= '9')
                {
                    width = width * 10 + (*currentChar - '0');
                    currentChar++;
                }
            }
            switch (*currentChar)
            {
                case '%':
                    outputBuffer[bufferIndex++] = '%';
                    if (bufferIndex == BUFFER_SIZE)
                    {
                        printBuffer(outputBuffer, &bufferIndex);
                        characterCount += bufferIndex;
                    }
                    break;
                case 'c':
                    {
                        ch = va_arg(args, int);
                        outputBuffer[bufferIndex++] = ch;
                        if (bufferIndex == BUFFER_SIZE)
                        {
                            printBuffer(outputBuffer, &bufferIndex);
                            characterCount += bufferIndex;
                        }
                    }
                    break;
                case 'd':
                case 'i':
                    {
                        long value;
                        if (flags & 0x10) 
                        {
                            value = va_arg(args, long);
                        }
                        else if (flags & 0x20) 
                        {
                            value = (short)va_arg(args, int);
                        }
                        else
                        {
                            value = va_arg(args, int);
                        }
                        printedCount = printInteger(value, flags, width, precision);
                        characterCount += printedCount;
                        flags = 0;
                        width = 0; 
                    }
                    break;
                case 's':
                    {
                        str = va_arg(args, char *);
                        printString(str);
                    }
                    break;
                case 'u':
                    {
                        if (flags & 0x10)
                        {
                            value = va_arg(args, unsigned long);
                        }
                        else if (flags & 0x20)
                        {
                            value = (unsigned short)va_arg(args, unsigned int);
                        }
                        else
                        {
                            value = va_arg(args, unsigned int);
                        }
                        printUnsigned(value, 10, 0, width, precision);
                        width = 0;
                        precision = -1;
                    }
                    break;
                case 'o':
                    {
                        if (flags & 0x10)
                        {
                            value = va_arg(args, unsigned long);
                        }
                        else if (flags & 0x20)
                        {
                            value = (unsigned short)va_arg(args, unsigned int);
                        }
                        else
                        {
                            value = va_arg(args, unsigned int);
                        }
                        printUnsigned(value, 8, 0, width, precision);
                        width = 0;
                        precision = -1;
                    }
                    break;
                case 'x':
                    {
                        if (flags & 0x10)
                        {
                            value = va_arg(args, unsigned long);
                        }
                        else if (flags & 0x20)
                        {
                            value = (unsigned short)va_arg(args, unsigned int);
                        }
                        else
                        {
                            value = va_arg(args, unsigned int);
                        }
                        printUnsigned(value, 16, 0, width, precision);
                        width = 0;
                        precision = -1;
                    }
                    break;
                case 'X':
                    {
                        if (flags & 0x10)
                        {
                            value = va_arg(args, unsigned long);
                        }
                        else if (flags & 0x20)
                        {
                            value = (unsigned short)va_arg(args, unsigned int);
                        }
                        else
                        {
                            value = va_arg(args, unsigned int);
                        }
                        printUnsigned(value, 16, 1, width, precision);
                        width = 0;
                        precision = -1;
                    }
                    break;
                case 'p':
                    {
                        void *ptr = va_arg(args, void *);
                        printPointer(ptr);
                    }
                    break;
                case 'S':
                    {
                        str = va_arg(args, char *);
                        printSpecialString(str);
                    }
                    break;
                case 'r':
                    {
                        str = va_arg(args, char *);
                        printReversedString(str);
                    }
                    break;
                case 'R' :
                    {
                        rot13_str = va_arg(args, char *);
                        printRot13String(rot13_str);
                    }
                    break;

                default:
                    break;
            }
        }
        else
        {
            outputBuffer[bufferIndex++] = *currentChar;
            if (bufferIndex == BUFFER_SIZE)
            {
                printBuffer(outputBuffer, &bufferIndex);
                characterCount += bufferIndex;
            }
        }
        currentChar++;
    }
	printBuffer(outputBuffer, &bufferIndex);
    	characterCount += bufferIndex;
	va_end(args);
return (characterCount);
}