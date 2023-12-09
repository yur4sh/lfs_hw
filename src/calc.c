#include "calc.h"

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a / b;
}

int factorial(int a)
{
    int f = 1;

    for (int i = f + 1; i <= a; ++i) {
        f *= i;
    }

    return f;
}

int squareroot(int a)
{
    int start = 1;
    int end = a;
    int result = 0;

    while (start <= end) {
        int mid = (start + end) / 2;
        int tmp = mid * mid;

        if (tmp == a) {
            result = mid;
            break;
        }

        if (tmp < a) {
            start = mid + 1;
            result = mid;
        }
        else
            end = mid - 1;
    }

    return result;
}