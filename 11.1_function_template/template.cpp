#include <iostream>
#include <limits>
using namespace std;

template <typename T, int N> // <template parameter, length of the array>
void print(T (& array)[N]) // Represents a reference to an array of length N , element type T and name is array .
{
    for(int i = 0; i < N; i++)
    {
        cout << array[i] << "\t";
    }
    cout << endl;
}

int main()
{
    int arr1[4] = {7, 3, 5, 1};
    double arr2[3] = {7.5, 6.1, 4.6};

    print(arr1);
    print(arr2);

    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
}