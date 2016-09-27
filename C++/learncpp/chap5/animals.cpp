#include <iostream>
#include <string>

enum class Animal
{
    PIG,
    CHICKEN,
    GOAT,
    CAT,
    DOG,
    OSTRICH
};

std::string getAnimalName(Animal animal)
{
    switch (animal) {
        case Animal::PIG:
            return "pig";
        case Animal::CHICKEN:
            return "chicken";
        case Animal::GOAT:
            return "goat";
        case Animal::CAT:
            return "cat";
        case Animal::DOG:
            return "dog";
        case Animal::OSTRICH:
            return "ostrich";
        default:
            return "getAnimalName(): Unhandled enumerator";
    }
}

void printNumberOfLegs(Animal animal)
{
    std::cout << "A " << getAnimalName(animal) << " has ";

    switch (animal)
    {
        case Animal::PIG:
        case Animal::GOAT:
        case Animal::CAT:
        case Animal::DOG:
            std::cout << "4";
            break;

        case Animal::CHICKEN:
        case Animal::OSTRICH:
            std::cout << "2";
            break;

        default:
            std::cout << "printNumberOfLegs(): Unhandled enumerator";
            break;
    }

    std::cout << " legs.\n";
}

int main(int argc, char const *argv[]) {
    printNumberOfLegs(Animal::CAT);
    printNumberOfLegs(Animal::CHICKEN);
    return 0;
}
