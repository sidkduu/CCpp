# include<iostream>
using namespace std;

// Use
// new      : Allocate an object memory in heap memory
// new[]    : Allocate memory for an array in heap memory
// delete   : Release the memory of an object in heap memory
// delete[] : Release the memory of an array in heap memory

int main()
{
    // Initialize size of the array and a pointer to the array
    int size;
    int * pArray;

    // Make sure size is greater than 0
    do{
        cout << "Enter the size of the array(>0): ";
        cin >> size;
    }while(size <= 0);

    // Create array in heap memory
    pArray = new int[size];
    // Initialize the array
    for(int i = 0; i < size; i++){
        cout << "Enter the value of element " << i << ": ";
        cin >> *(pArray+i);
    }

    // Print the array
    cout << "The elemnts of the array are: "<< endl;
    for(int i = 0; i < size; i++){
        cout << *(pArray+i) << " ";
    }
    cout << endl;

    // Delete the array
    delete[] pArray;

    system("pause");
    return 0;
}