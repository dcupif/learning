#include <iostream>

int factorial(int n)
{
    if (n<1)
        return 1;
    else
        return n*factorial(n-1);
}

int main(int argc, char const *argv[])
{
    for (size_t i = 0; i < 7; i++)
        std::cout << i << "! = " << factorial(i) << "\n";
    return 0;
}
