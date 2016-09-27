#include <iostream>

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main(int argc, char const *argv[])
{
    std::cout << "Enter a 1st number: ";
    int x;
    std::cin >> x;

    std::cout << "Enter a 2nd number: ";
    int y;
    std::cin >> y;

    std::cout << "\nBefore swapping:\n";
    std::cout << "\tValue of x: " << x << "\n";
    std::cout << "\tValue of y: " << y << "\n";

    swap(x, y);

    std::cout << "\nAfter swapping:\n";
    std::cout << "\tValue of x: " << x << "\n";
    std::cout << "\tValue of y: " << y << "\n";

    return 0;
}
