#include <iostream>

int sumNumbers(int x)
{
    if (x<9)
        return x;
    else
        return sumNumbers(x / 10) + x % 10;
}

int main(int argc, char const *argv[])
{
    std::cout << sumNumbers(93427) << std::endl;
    return 0;
}
