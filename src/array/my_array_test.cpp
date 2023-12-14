#include "my_array.hpp"
#include <iostream>

int main()
{
    using namespace my_stl;
    my_array<int, 5> intArray;

    intArray.fill(42);

    std::cout << "Is the array empty? " << (intArray.empty() ? "Yes" : "No") << "\n";

    // Access elements using operator[]
    std::cout << "Array elements using operator[]: ";
    for (std::size_t i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << "\n";

    // Modify elements using at() and front()
    intArray.at(2) = 99;
    intArray.front() = 10;

    // Access elements using const operator[]
    const my_array<int, 5>& constIntArray = intArray;
    std::cout << "Array elements using const operator[]: ";
    for (std::size_t i = 0; i < constIntArray.size(); i++) {
        std::cout << constIntArray[i] << " ";
    }
    std::cout << "\n";

    // Check front() and back()
    std::cout << "Front element: " << intArray.front() << "\n";
    std::cout << "Back element: " << intArray.back() << "\n";

    // Check empty() and size()
    std::cout << "Is the array empty? " << (intArray.empty() ? "Yes" : "No") << "\n";
    std::cout << "Array size: " << intArray.size() << "\n";
    std::cout << "Array max size: " << intArray.max_size() << "\n";

    return 0;
}
