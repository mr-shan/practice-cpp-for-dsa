
#include <iostream>

using namespace std;

int* setUnion(int* arr1, int length1, int* arr2, int length2)
{
    int totalLength = length1 + length2;
    int *combinedArray = new int[length2 + length1];
    
    int i = 0, j = 0, k = 0;
    
    while (i < length1 && j < length2)
    {
        if (arr1[i] < arr2[j])
            combinedArray[k++] = arr1[i++];
        else if (arr1[i] > arr2[j])
            combinedArray[k++] = arr2[j++];
        else
        {
            combinedArray[k++] = arr1[i];
            i++;
            j++;
        }
    }
    
    for (int r = i; r < length1; ++r)
        combinedArray[k++] = arr1[r];
        
    for (int r = j; r < length2; ++r)
        combinedArray[k++] = arr2[r];
    
    return combinedArray;
}


int* setIntersection(int* arr1, int length1, int* arr2, int length2)
{
    int *combinedArray = new int[4];
    
    int i = 0, j = 0, k = 0;
    
    while (i < length1 && j < length2)
    {
        if (arr1[i] < arr2[j]) 
            i++;
        else if (arr2[j] < arr1[i]) 
            j++;
        else
        {
            combinedArray[k++] = arr1[i];
            i++;
            j++;
        }
    }
    
    return combinedArray;
}

int* setDifference(int* arr1, int length1, int* arr2, int length2)
{
    int *combinedArray = new int[10];
    
    int i = 0, j = 0, k = 0;
    
    while (i < length1 && j < length2)
    {
        if (arr1[i] < arr2[j]) 
            combinedArray[k++] = arr1[i++];
        else if (arr2[j] < arr1[i]) 
            j++;
        else
        {
            i++;
            j++;
        }
    }
    
    return combinedArray;
}

void printSet(int *arrSet, int length)
{
    for (int i = 0; i < length; ++i)
        cout << arrSet[i] << " ";
}

int main()
{
    int arr1[] = { 1, 2, 5, 7, 9 };
    int arr2[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
    
    int *uni = setUnion(arr1, 5, arr2, 8);
    int *intersect = setIntersection(arr1, 5, arr2, 8);
    int *diff = setDifference(arr2, 8, arr1, 5);
    
    cout << "Set 1: { ";
    printSet(arr1, 5); 
    cout << "}\nSet 2: { ";
    printSet(arr2, 8);
    cout << "}\n\n";
    
    cout << "Union of two sets: { ";
    printSet(uni, 9);
    cout << "}\n";
    
    cout << "Intersection of two sets: { ";
    printSet(intersect, 4);
    cout << "}\n";
    
    cout << "Difference between two sets (Set2 - Set1): { ";
    printSet(diff, 10);
    cout << "}\n"; 

    return 0;
}
