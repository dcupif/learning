#include "io.h"

int main(int argc, char const *argv[]) {
    int op1 = readNumber();
    int op2 = readNumber();
    writeAnswer(op1+op2);
    return 0;
}
