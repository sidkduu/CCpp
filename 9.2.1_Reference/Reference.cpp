/* Declare and initialize the original and reference variables, and then use the original or reference variables to access the common values */
# include<iostream>
# include<vector>
using namespace std;

// A reference is an alias for an object that must be initialized at definition time, and once initialized, bound permanently.
// References can't point to null values.
// The reference itself doesn't take up extra memory space, it's just an alias for an object.
// When using references, you don't need to use additional operators, and you can access the referenced objects directly by using the reference name.
// Function parameter passing: When you need to modify the arguments provided by the caller inside the function, you can use the reference as the function parameter. This avoids duplicating objects and increases efficiency.
// Return Object References: Functions can return references to an object, so that the object can continue to be used outside of the function and avoid duplicating the object.

// Function parameter passing
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Return Object References
vector<int>& getVector() {
    static vector<int> vec = {1, 2, 3};
    return vec;
}

int main()
{
    // Create a referencing relationship
    int score = 92;
    int& refScore = score;

    // Use data variables
    cout << "Accessing value through data variable." << endl;
    cout << "Score: " << score << endl;

    // Use reference variables
    cout << "Accessing value through reference variable." << endl;
    cout << "Score: " << refScore << endl;

    // Change the value of the original variable
    refScore = 100;
    cout << "Change value through reference variable(100)." << endl;
    cout << "Score: " << score << endl;

    // Function parameter passing
    int num1 = 10;
    int num2 = 20;
    swap(num1, num2);
    cout << num1 << " " << num2 << endl; // Outpt: 20 10

    // Return Object References
    vector<int>& vec = getVector();
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}


