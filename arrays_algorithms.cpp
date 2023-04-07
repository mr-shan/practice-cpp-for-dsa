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
    
    for (int i = 0; i < length - 1; ++i)
    {
        arrH[arr[i]]++;
    }
    
    for (int i = 1; i < high; ++i)
        if (arrH[i] > 1)
            printf("%d is duplicate at %d times\n", i, arrH[i]);
}
