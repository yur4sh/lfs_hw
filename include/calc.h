#ifndef CALC_H
#define CALC_H

enum Opcode {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    FACTORIAL,
    SQRT,
    UNKNOWN = 255
};

typedef struct calc_t {
    int a;
    int b;
    enum Opcode c;

    int errcode;
}input_t;

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int factorial(int a);
int squareroot(int a);

#endif // CALC_H