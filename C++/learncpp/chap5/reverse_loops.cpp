#include <iostream>

// Loop between 1 and 5
int main()
{
    int outer = 1;
    while (outer <= 5)
    {
        // loop between 1 and outer
        int inner = 5;
        while (inner >= 1)
        {
            if (inner <= outer)
                std::cout << inner << " ";
            else
                std::cout << "  ";
            inner--;
        }

        // print a newline at the end of each row
        std::cout << "\n";
        ++outer;
    }

    return 0;
}
