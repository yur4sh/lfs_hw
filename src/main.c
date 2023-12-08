#include "ui.h"

#define BUFFLEN 128

int main()
{
    char op_txt[BUFFLEN] = {0};
    input_t numbers = { .a = 0, .b = 0, .c = UNKNOWN, .errcode = ERR_DEFAULT };
    int result = 0;

    printf("Enter operation to perform (add, sub, mul, div, fact, sqrt): ");
    if (!scanf("%s", op_txt)) {
        fprintf(stderr, "Error! Invalid input.\n");
        return EXIT_FAILURE;
    }
    numbers.c = get_operation(op_txt);

    if (numbers.c == UNKNOWN) {
        fprintf(stderr, "Error! Unknown operation type <%s>.\n", op_txt);
        return EXIT_FAILURE;
    }

    printf("\n");
    printf("Enter number(s) for this operation (if operation is unary, put any number as 2nd arg): ");
    if (!scanf("%d %d", &numbers.a, &numbers.b)) {
        fprintf(stderr, "Error! Invalid input.\n");
        return EXIT_FAILURE;
    }

    printf("\n");
    if (do_operation(&numbers, &result)) {
        printerr(numbers.errcode);
        return EXIT_FAILURE;
    }
    printf("Result: %d\n", result);

    return EXIT_SUCCESS;
}