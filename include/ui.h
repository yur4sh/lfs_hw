#ifndef UI_H
#define UI_H

#include "calc.h"

#include <stdio.h>
#include <stdlib.h>

#define ERR_SUCCESS 0
#define ERR_ZERODIV 1
#define ERR_NEGSQRT 2
#define ERR_NEGFACT 3
#define ERR_DEFAULT 255

enum Opcode get_operation(char* text);
int do_operation(input_t* input, int* result);
void printerr(int errcode);

#endif // UI_H