#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define BUFFER_SIZE 1024

/* Helper Functions  for Printing*/
void printCharacter(char ch);
void printBuffer(char buffer[], int *bufferIndex);

/* Conversion Specifier Functions */
void printString(const char *str);  /* %s */
int printInteger(long value, int flags, int width, int precision);  /* %d, %i */
void printUnsigned(unsigned long  value, int base, int uppercase, int width, int precision);  /* %u, %o, %x, %X */
void printSpecialString(const char *str);  /* %S */
void printPointer(const void *ptr);  /* %p */
void printReversedString(const char *str);  /* %r */
void printRot13String(const char *str);

/* Main Printf Function */
int _printf(const char *format, ...);

#endif /* MAIN_H */

