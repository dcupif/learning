#include <iostream>

int main(int argc, char const *argv[]) {
    char myChar = 'a';
    while (myChar <= 'z') {
        std::cout << myChar << ":\t" << static_cast<int>(myChar) << "\n";
        myChar++;
    }
    return 0;
}
