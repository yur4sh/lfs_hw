#include "lower.h"

int to_lowercase(char* in, char* out)
{
    int length = strlen(in) - 1;

    if (!in || !out || length == 0)
        return EXIT_FAILURE;

    for (int i = 0; i < length; ++i)
        out[i] = (IS_UPPER(in[i]) ? in[i] + ASCII_SHIFT : in[i]);

    return EXIT_SUCCESS;
}