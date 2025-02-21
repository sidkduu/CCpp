#include <iostream>
using namespace std;

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
        // try-catch block
        try
        {
            if(num2 == 0)
            {
                throw 0;        // throw an exception
            }
            else
            {
                result = (double)num1 / (double)num2;
                cout << "The result is: " << result << endl;
            }
        }
        catch(int x)
        {
            cout << "Division by zero is not allowed! Exception value: " << x << endl;
            
        }
    }

    system("pause");
    return 0;
}