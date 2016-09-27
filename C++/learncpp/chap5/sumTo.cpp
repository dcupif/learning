#include <iostream>

int sumTo(int x)
{
    int res = 0;

    for (int count=0; count<=x; ++count)
        res+=count;

    return res;
}

int main(int argc, char const *argv[])
{
    std::cout << "Enter a number: ";
    int x;
    std::cin >> x;

    std::cout << "The sum of all numbers from 1 to " << x << " is: " <<
        sumTo(x) << "\n";

    return 0;
}
