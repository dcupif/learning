#include <iostream>

int doubleNumber(int x)
{
    return x*2;
}

int main(int argc, char const *argv[])
{
    std::cout << "Please enter the number to be doubled: ";
    int x = 0;
    std::cin >> x;
    std::cout << doubleNumber(x) << std::endl;
    return 0;
}
