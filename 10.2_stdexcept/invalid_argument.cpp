// Logical errors are related to function prerequisites; logic_error <---- domain_error, length_error, out_of_range, invalid_argument
// Runtime errors are related to function postconditions; runtime_error <---- underflow_error, overflow_error, range_error
// bad_exception, bad_alloc, bad_typeid, bad_cast, failure, exception(stream fault)

#include <iostream>
#include <stdexcept>
#include <limits>
using namespace std;

int quitient(int first, int second);
int main()
{
    int num1, num2;
    double result;
    for(int i = 0; i < 3 ; i++)
    {
        cout << "Enter an integer: ";
        cin >> num1;
        cout << "Enter another integer: ";
        cin >> num2;
        // try-catch block, catch exception from function
        try
        {
            cout << "Result of division: " << quitient(num1, num2) << endl;

        }
        catch(invalid_argument ex)
        {
            cout << ex.what() << endl;
            
        }
    }

    std::cout << "Press any key to continue..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
}

int quitient(int first, int second)
{
    if(second == 0)
    {
        throw invalid_argument("Error! Divisor cannot be zero!");
    }
    return first / second;
}