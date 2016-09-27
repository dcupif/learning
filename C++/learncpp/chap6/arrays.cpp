#include <iostream>

int main(int argc, char const *argv[])
{
    const int arrayLength(9);
    int array[arrayLength] = { 4, 6, 7, 3, 8, 2, 1, 9, 5 };

    for (size_t i = 0; i < arrayLength; ++i) {
        std::cout << array[i] << " ";
    }

    std::cout << "\n";

    int x;

    do {
        std::cout << "Enter a number between 1 and " << arrayLength << ": ";
        std::cin >> x;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
    } while( x < 1 || x > arrayLength);

    for (size_t i = 0; i < arrayLength; i++) {
        if (array[i]==x)
        {
            std::cout << "Index de l'élément " << x << ": " << i << "\n";
            break;
        }
    }

    return 0;
}
