#include <iostream>

using namespace std;

int main()
{
    int arr[4];
    arr[0] = 5;
    arr[1] = 2;
    arr[2] = 2323;
    
    int arr2[10] = {1, 2, 3, 4, 5};
    
    cout << "The size of given array is " << sizeof(arr) << " bytes." << endl;
    cout << "This is an empty array " << sizeof(arr2);
    cout << arr2[9] << endl;
    cout << arr2[8] << endl;
    
    for (int i = 0; i < 10; ++i)
    {
        cout << arr2[i] << endl;
    }
    
    int size;
    cout << "Enter the size of Array: ";
    cin >> size;
    
    int arr2[size];
    
    for (int i:arr2)
    {
        cout << i << endl;
    }

    

    return 0;
}
