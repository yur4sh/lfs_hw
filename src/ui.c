#include "ui.h"

#include <string.h>

enum Opcode get_operation(char* text)
{
    if (!text)
        return UNKNOWN;

    if (!strcmp(text, "add"))
        return ADD;
    if (!strcmp(text, "sub"))
        return SUBTRACT;
    if (!strcmp(text, "mul"))
        return MULTIPLY;
    if (!strcmp(text, "div"))
        return DIVIDE;
    if (!strcmp(text, "fact"))
        return FACTORIAL;
    if (!strcmp(text, "sqrt"))
        return SQRT;

    return UNKNOWN;
}

int do_operation(input_t* input, int* result)
{
    if (!input || !result)
        return EXIT_FAILURE;

    switch (input->c) {
        case ADD:
            *result = add(input->a, input->b);
            break;
        case SUBTRACT:
            *result = subtract(input->a, input->b);
            break;
        case MULTIPLY:
            *result = multiply(input->a, input->b);
            break;
        case DIVIDE:
            if (input->b == 0) {
                input->errcode = ERR_ZERODIV;
                return EXIT_FAILURE;
            }
            *result = divide(input->a, input->b);
            break;
        case SQRT:
            if (input->a < 0) {
                input->errcode = ERR_NEGSQRT;
                return EXIT_FAILURE;
            }
            *result = squareroot(input->a);
            break;
        case FACTORIAL:
            if (input->a < 0) {
                input->errcode = ERR_NEGFACT;
                return EXIT_FAILURE;
            }
            *result = factorial(input->a);
            break;
        default:
            break;
    }

    input->errcode = ERR_SUCCESS;
    return EXIT_SUCCESS;
}

void printerr(int errcode)
{
    if (errcode == ERR_SUCCESS) {
        printf("Success!\n");
        return;
    }
    if (errcode == ERR_ZERODIV) {
        fprintf(stderr, "Error! Division by zero.\n");
        return;
    }
    if (errcode == ERR_NEGSQRT) {
        fprintf(stderr, "Error! Square root from negative number.\n");
        return;
    }
    if (errcode == ERR_NEGFACT) {
        fprintf(stderr, "Error! Factorial from negative number.\n");
        return;
    }
}