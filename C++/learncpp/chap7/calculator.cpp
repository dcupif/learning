#include <iostream>

typedef int (*arithmeticFcn)(int,int);

struct arithmeticStruct
{
    char op;
    arithmeticFcn fcn;
};

int getInteger()
{
    std::cout << "Please enter a integer: ";
    int x;
    std::cin >> x;
    return x;
}

char getOperation()
{
    char op;
    do
    {
        std::cout << "Please choose and operation ('+', '-', '*', '/'): ";
        std::cin >> op;
    } while(op != '+' && op != '-' && op != '*' && op != '/');
    return op;
}

int add(int x, int y)
{
    return x + y;
}

int substract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return x / y;
}

static arithmeticStruct arithmeticArray[]
{
    { '+', add },
    { '-', substract },
    { '*', multiply },
    { '/', divide }
};

arithmeticFcn getArithmeticFunction(char op)
{
    for ( const auto &element : arithmeticArray )
    {
        if ( element.op == op )
            return element.fcn;
    }
    return add;
}

int main(int argc, char const *argv[])
{
    int x = getInteger();
    char op = getOperation();
    int y = getInteger();

    arithmeticFcn fcn = getArithmeticFunction(op);

    std::cout << x << ' ' << op << ' ' << y << " = " << fcn(x,y) << "\n";

    return 0;
}
