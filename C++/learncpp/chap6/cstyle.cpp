#include <iostream>

void printCString(const char *string)
{
    while (*string != '\0') {
        std::cout << *string;
        ++string;
    }
}

int main(int argc, char const *argv[])
{
    printCString("Hello world!");
    return 0;
}
