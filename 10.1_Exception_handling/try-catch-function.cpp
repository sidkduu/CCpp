#include <iostream>
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
            cout << "Result: " << quitient(num1, num2) << endl;

        }
        catch(int x)
        {
            cout << "Division by zero is not allowed! Exception value: " << x << endl;
            
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
        throw -1;
    }
    return first / second;
}