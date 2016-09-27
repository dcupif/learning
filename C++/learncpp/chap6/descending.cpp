#include <algorithm> // for std::swap, use <utility> instead if C++11
#include <iostream>

int main()
{
    const int length = 5;
    int array[length] = { 30, 50, 20, 10, 40 };

    // Step through each element of the array
    for (int startIndex = 0; startIndex < length; ++startIndex)
    {
        // smallestIndex is the index of the smallest element we've encountered so far.
        int maxIndex = startIndex;

        // Look for smallest element remaining in the array (starting at startIndex+1)
        for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
        {
            // If the current element is smaller than our previously found smallest
            if (array[currentIndex] > array[maxIndex])
                // This is the new smallest number for this iteration
                maxIndex = currentIndex;
        }

        // Swap our start element with our smallest element
        std::swap(array[startIndex], array[maxIndex]);
    }

    // Now print our sorted array as proof it works
    for (int index = 0; index < length; ++index)
        std::cout << array[index] << ' ';

    return 0;
}
