#include <iostream>
#include <string>

void selection_sort(std::string *array, int length)
{
    // Step through each element of the array
    for (int i = 0; i < length; ++i)
    {
        int smallestIndex = i;

        // Look for the smallest element remaining in the array
        for (int j = i+1; j < length; ++j)
        {
            if (array[j]<array[i])
                smallestIndex = j;
        }

        // Swap our start element with our smallest element
        std::swap(array[i], array[smallestIndex]);
    }
}

int main(int argc, char const *argv[])
{
    std::cout << "How many names would you like to enter? ";
    int nbNames;
    std::cin >> nbNames;

    // Allocate an array to hold the names
    std::string *names = new std::string[nbNames];

    // Ask the user to enter all names
    for (int i = 0; i < nbNames; i++)
    {
        std::cout << "Enter name #" << i+1 << ": ";
        std::cin >> names[i];
    }

    // Sort the array
    selection_sort(names, nbNames);

    std::cout << "\nHere is your sorted list:\n";

    // Print the sorted array
    for (int i = 0; i < nbNames; i++)
    {
        std::cout << "Name #" << i+1 << ": " << names[i] << "\n";
    }

    // do not forget to use array delete
    delete[] names;
    names = 0;

    return 0;
}
