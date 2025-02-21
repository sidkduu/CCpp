#include <iostream>
#include <string>
#include <cstring>
#include <limits>
using namespace std;

template <typename T> 
T smaller(const T& first, const T& second)
{
    if(first < second)
    {
        return first;
    }
    return second;
}

// template function specification, <const char*> clarified the target type
// "const char* const&" represents a constant reference to a constant pointer that points to a constant character
//      Can't let it reference another pointer
//      Can't modify the content of the character it points to by the referenced pointer
template<>
const char* smaller<const char*>(const char* const& first, const char* const& second)
{
    if (std::strcmp(first, second) < 0)
    {
        return first;
    }
    return second;
}

int main()
{
    string str1 = "Hello";
    string str2 = "Hi";
    cout << "Smaller(Hello, Hi):" << smaller(str1, str2) << endl;       // Hello (Dictionary order comparison)

    const char* s1 = "Bye";
    const char* s2 = "Bye Bye";
    cout << "Smaller(Bye, Bye Bye):" << smaller(s1, s2) << endl;        // Bye

    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
}