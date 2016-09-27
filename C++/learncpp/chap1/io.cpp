#include <iostream>

int readNumber()
{
    std::cout << "Please enter a number to be summed: ";
    int x = 0;
    std::cin >> x;
    return x;
}

void writeAnswer(int answer)
{
    std::cout << "Result: " << answer << std::endl;
}
