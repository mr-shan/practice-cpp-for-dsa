#include <iostream>

using namespace std;

// function to find missing element from the natural elements
// use the sum to find the missing element here.
// the formula for that is sum = n(n + 1) / 2
// if first element is not 1, then use the difference between element and it's index.
// it should be constant.
int findMissingElement(int *arr, int length)
{
    int firstElement = arr[0], lastElement = arr[length - 1];
    
    if (firstElement == 1)
    {
        // use the formula n(n + 1) / 2
        int sum = 0;
        for (int i = 0; i < length; ++i)
            sum += arr[i];
        
        int expectedSum = (lastElement * (lastElement + 1)) / 2;
        return expectedSum - sum;
        
    } else {
        // find the difference between the element and it's index
        int diff = firstElement;
        
        for (int i = 1; i < length; ++i)
        {
            if (arr[i] - i != diff) {
                return i + diff;
            }
        }
        return 0;
    }
}

// find multiple missing elements from the series of numbers
void findMultipleMissingElements(int *arr, int length)
{
    // get the first and last element. 
    // also get the difference between first element and first index.
    int firstElement = arr[0], lastElement = arr[length - 1];
    int diff = firstElement;
    
    for (int i = 1; i < length; ++i)
    {
        int currentDiff = arr[i] - i;
        
        // if difference between an element and it's index is not `diff`,
        // we have one or more missing elements. 
        // number of elements missing is equal to currentDiff - diff
        // so we can find out missing element by adding diff + i
        // for more than one missing elements, increment diff till it's equal to currentDiff.
        if (currentDiff != diff) {
            while (diff < currentDiff)
                cout << " " << i + diff++;
        }
    }
}

// find missing elements for unsorted array using hash array
void findMissingElementsFromUnsortedArray(int *arr, int length)
{
    int high = arr[0], low = arr[0];
    for (int i = 0; i < length; ++i)
    {
        high = arr[i] > high ? arr[i] : high;
        low = arr[i] < low ? arr[i] : low;
    }
    
    int arrH[high + 1] = { 0 };
    for (int i = 0; i < length; ++i)
        ++arrH[arr[i]];
    
    cout << endl;
        
    for (int i = 1; i <= high; ++i)
        if (arrH[i] == 0)
            cout << i << " ";
}

// find duplicate elements in sorted array
void findDuplicates(int *arr, int length)
{
    int lastDuplicate = 0;
    for (int i = 0; i < length - 1; ++i)
    {
        if (arr[i] == arr[i + 1] && arr[i] != lastDuplicate) {
            cout << arr[i] << " ";
            lastDuplicate = arr[i];
        }
    }
}

// find duplicates using hash
void findDuplicatesUsingHash(int *arr, int length)
{
    int high = arr[0];
    for (int i = 0; i < length; ++i)
        high = arr[i] > high ? arr[i] : high;
    
    int arrH[high + 1] = { 0 };
    
    for (int i = 0; i < length; ++i)
        arrH[arr[i]]++;
    
    for (int i = 1; i < high; ++i)
        if (arrH[i] > 1)
            printf("%d is duplicate at %d times\n", i, arrH[i]);
}

// find duplicates using iterations
void fundDuplicatesInUnsortedArray(int *arr, int length)
{
    for (int i = 0; i < length - 1; ++i)
    {
        int duplicates = 1;
        
        if (arr[i] == -1) continue;
        
        for (int j = i + 1; j < length; ++j)
        {
            if (arr[i] == arr[j]) 
            {
                duplicates++;
                arr[j] = -1;
            }
        }
        
        if (duplicates > 1)
            printf("%d is duplicate at %d times\n", arr[i], duplicates);
    }
}

// Utility functions
int getMaxNum(int *arr, int length)
{
  int max = 0;
  for (int i = 0; i < length; ++i)
    max = arr[i] > max ? arr[i] : max;
  return max;
}

void printArray(int *arr, int length)
{
  cout << "array = [ ";
  for (int i = 0; i < length; ++i)
    cout << arr[i] << " ";
  cout << "]\n";
}


// Iterative method of finding pair of elements with required sum
void findPairOfElementsWithSum(int *arr, int length, int sum)
{
  for (int i = 0; i < length - 1; ++i)
  {
    for (int j = i + 1; j < length; ++j)
    {
      if (arr[i] + arr[j] == sum)
        printf("Sum of (%d+%d) = %d\n", arr[i], arr[j], sum);
    }
  }
}

// Use of hashing to find a pair of elements with required sum
void findPairOfElementsWithSum2(int *arr, int length, int sum)
{
  int maxNum = getMaxNum(arr, length);
  int arrH[maxNum + 1] = { 0 };
  
  for (int i = 0; i < length; ++i)
  {
    arrH[arr[i]] = 1;
    if (arrH[sum - arr[i]] == 1 && arr[i] != sum - arr[i])
      printf("Sum of (%d+%d) = %d\n", arr[i], sum - arr[i], sum);
  }
}

// Use of sorted array to find a pair of elements with required sum
void findPairOfElementsWithSumSortedArray(int *arr, int length, int sum)
{
  int low = 0, high = length - 1;
  while (low < high)
  {
    int currentSum = arr[low] + arr[high];
    if (currentSum > sum) high--;
    else if (currentSum < sum) low++;
    else 
      printf("Sum of (%d+%d) = %d\n", arr[low++], arr[high--], sum);
  }
}

int main()
{
    int arr[] = { 5, 6, 8, 9, 10, 11 };
    int arr2[] = { 1, 4, 5, 6, 9, 14, 15, 16 };
    int arr3[] = { 5, 2, 6, 7, 1, 9 };
    int arr4[] = { 1, 2, 5, 7, 8, 8, 9, 10, 15, 15, 15, 17 };
    int arr5[] = { 11, 12, 16, 9, 6, 1, 11, 11, 6 };
    int missingElement = findMissingElement(arr, 6);
    findMultipleMissingElements(arr2, 8);
    cout << endl;
    
    cout << "Missing element is : " << missingElement << "\n\n";
    
    cout << endl;
    // findMissingElementsFromUnsortedArray(arr3, 6);
    findDuplicates(arr4, 12);
    cout << endl;
    cout << endl;
    cout << "Duplicates using hash\n";
    findDuplicatesUsingHash(arr5, 9);

    cout << "\n\nDuplicates using iterations\n";
    fundDuplicatesInUnsortedArray(arr5, 9);
    return 0;
}
