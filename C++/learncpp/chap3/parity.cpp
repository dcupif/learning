#include <iostream>

bool isEven(int x)
{
    return x%2==0;
}

int main()
{
    std::cout << "Please enter the number to test its parity: ";
    int x;
    std::cin >> x;
    if (isEven(x)) {
        std::cout << "The number " << x << " is even.\n";
    } else {
        std::cout << "The number " << x << " is odd.\n";
    }
    return 0;
}
