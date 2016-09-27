#include <iostream>

int main() {

    const int length(9);
    int array[length] = { 6, 3, 2, 9, 7, 1, 5, 4, 8 };

    // We'll need to do this as many times as there are elements in the array-1
    for (size_t i = 0; i < length; i++) {

        // Keep track of whether any elements were swapped this iteration
        bool swapped(false);

        // Search through all elements up to the end of the array - 1
        // The last element has no pair to compare against
        for (size_t j = 0; j < length - i - 1; j++) {
            if (array[j] > array[j+1])
            {
                std::swap(array[j], array[j+1]);
                swapped = true;
            }
        }

        // If we haven't swapped any elements this iteration, we're done early
        if (!swapped)
        {
            // Iteration is 0-based, but counting iterations is 1-based
            std::cout << "Early termination on iteration " << i+1 << "\n";
            break;
        }
    }

    // Now print our sorted array as proof it works
    for (size_t i = 0; i < length; i++) {
        std::cout << array[i] << " ";
    }

    return 0;

}
