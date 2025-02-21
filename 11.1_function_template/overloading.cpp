#include <iostream>
#include <limits>
using namespace std;

template <typename T> 
T smallest(const T& first, const T& second)
{
    if(first < second)
    {
        return first;
    }
    return second;
}

template <typename T>
T smallest(const T& first, const T& second, const T& third)
{
    return smallest(smallest(first, second), third);
}


int main()
{
    cout << "Smallest of 17, 12, and 27 is  ";
    cout << smallest(17, 12, 27) << endl;

    cout << "Smallest of 8.5, 4.1, and 19.75 is  ";
    cout << smallest(8.5, 4.1, 19.75) << endl;

    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
}