#include "ui.h"
#include "lower.h"
#include "upper.h"

#define BUFFLEN 128
#define FLUSH_STDIN(c) while ((c = getchar()) != '\n' && c != EOF);

static int task_1()
{
    char op_txt[BUFFLEN] = {0};
    input_t numbers = { .a = 0, .b = 0, .c = UNKNOWN, .errcode = ERR_DEFAULT };
    int result = 0;

    printf("=========================== TASK 1 ===========================\n\n");
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
    printf("==============================================================\n\n\n\n");

    return EXIT_SUCCESS;
}

static int task_2()
{
    char input[BUFFLEN] = {0};
    char converted[BUFFLEN] = {0};

    int c;
    FLUSH_STDIN(c);

    printf("=========================== TASK 2 ===========================\n\n");

    printf("Enter text to be converted: ");
    if (!fgets(input, BUFFLEN, stdin)) {
        fprintf(stderr, "Error! Couldn't read text from input\n");
        return EXIT_FAILURE;
    }

    if (to_lowercase(input, converted)) {
        fprintf(stderr, "Error! Couldn't convert '%s' into lower case.\n", input);
        return EXIT_FAILURE;
    }
    printf("Converted into lower case: '%s'\n", converted);

    memset(converted, 0, BUFFLEN);

    if (to_uppercase(input, converted)) {
        fprintf(stderr, "Error! Couldn't convert '%s' into lower case.\n", input);
        return EXIT_FAILURE;
    }
    printf("Converted into upper case: '%s'\n", converted);

    printf("==============================================================\n\n\n\n");

    return EXIT_SUCCESS;
}

int main()
{
    return task_1() ? EXIT_FAILURE : task_2();
}