#include <iostream>

enum ItemTypes
{
    HEALTH_POTION,
    TORCHE,
    ARROW,
    MAX_ITEMS
};

int countTotalItems(int *items)
{
    int totalItems = 0;

    for (size_t i = 0; i < MAX_ITEMS; i++) {
        totalItems += items[i];
    }

    return totalItems;
}

int main(int argc, char const *argv[])
{
    int items[MAX_ITEMS] = { 2, 5, 10 };

    std::cout << "The player has " << countTotalItems(items) <<
        " items in total.\n";

    return 0;
}
