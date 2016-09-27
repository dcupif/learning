#include <iostream>
#include "constants.h"

double getInitialHeight()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    int x;
    std::cin >> x;
    return x;
}

double calculateHeight(double initialHeight, int seconds)
{
    return initialHeight - constants::gravity * seconds * seconds / 2;
}

void printHeight(double initialHeight, int seconds) {
    double height = calculateHeight(initialHeight, seconds);
    if (height > 0) {
        std::cout << "At " << seconds << " seconds, the ball is at height: " <<
            height << " meters\n";
    } else {
        std::cout << "At " << seconds <<
            " seconds, the ball is on the ground.\n";
    }
}

int main()
{
    double initialHeight = getInitialHeight();
    printHeight(initialHeight,0);
    printHeight(initialHeight,1);
    printHeight(initialHeight,2);
    printHeight(initialHeight,3);
    printHeight(initialHeight,4);
    printHeight(initialHeight,5);
    return 0;
}
