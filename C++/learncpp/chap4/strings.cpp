#include <iostream>

int main(int argc, char const *argv[]) {

    std::cout << "Enter your full name: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Enter your age: ";
    int age;
    std::cin >> age;
    std::cin.ignore();

    std::cout << "You've lived " << static_cast<double>(age) / name.length() <<
        " years for each letter in your name.\n";

    return 0;
}
