class NumbersArray
{
private:
    int *array;
    int size;
    int length;
    
public:
    NumbersArray(int size)
    {
        this -> size = size;
        this -> length = 0;
        this -> array = new int[size];
    }
    
    NumbersArray(int arr[], int length, int size)
    {
        this -> size = size;
        this -> length = length;
        this -> array = new int[size];
        for (int i = 0; i < length; ++i)
        {
            this -> array[i] = arr[i];
        }
    }
    
    void print() {
        for (int i = 0; i < this -> length; ++i)
            std::cout << this -> array[i] << " ";
        std::cout << std::endl;
    }

    int append(int number)
    {
        if (this -> length >= this -> size)
            return -1;
        
        this -> array[this -> length] = number;
        this -> length++;
        
        return number;
    }
    
    int insert(int number, int index)
    {
        if (index > this -> length || index < 0)
            return -1;
        
        for (int i = this -> length; i >= index; i--)
            this -> array[i] = this -> array[i - 1];
        this -> array[index] = number;
        this -> length++;
        
        return number;
    }
    
    int insertSorted(int number)
    {
        if (this -> length == this -> size || !this -> isSorted())
            return -1;
        
        int i = this -> length - 1;
        while(i >= 0 && this -> array[i] > number)
        {
            this -> array[i + 1] = this -> array[i];
            i--;
        }
        this -> array[i + 1] = number;
        this -> length++;
        
        return number;
    }
    
    int remove(int index)
    {
        if (index < 0 || index >= this -> length)
            return -1;
        
        int deletedNumber = this -> array[index];
        
        for (int i = index; i < this -> length; ++i)
            this -> array[i] = this -> array[i + 1];
        
        this -> length--;
        return deletedNumber;
    }
    
    int get(int index)
    {
        if (index < 0 || index > this -> length)
            return -1;
        return this -> array[index];
    }
    
    int set(int index, int number)
    {
        if (index < 0 || index > this -> length)
            return -1;
        
        this -> array[index] = number;
        return number;
    }
    
    int max()
    {
        int maxNum = this -> array[0];
        for (int i = 1; i < this -> length; ++i)
            if (this -> array[i] > maxNum)
                maxNum = this -> array[i];
            
        return maxNum;
    }
    
    int min()
    {
        int minNum = this -> array[0];
        for (int i = 1; i < this -> length; ++i)
            if (this -> array[i] < minNum)
                minNum = this -> array[i];
            
        return minNum;
    }
    
    int sum()
    {
        int sum = 0;
        for (int i = 0; i < this -> length; ++i)
            sum += this -> array[i];
        
        return sum;
    }
    
    int avg()
    {
        return this -> sum() / this -> length;
    }
    
    int linearSearch(int number)
    {
        for (int i = 0; i < this -> length; ++i)
            if (this -> array[i] == number)
                return i;
        
        return -1;
    }
    
    int binarySearch(int key)
    {
        int left = 0, right = this -> length, mid;
        
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (this -> array[mid] == key)
                return mid;
            else if (this -> array[mid] < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
    
    void reverse()
    {
        int start, end;
        for (start = 0, end = this -> length - 1; start < end; ++start, --end)
        {
            int temp = this -> array[start];
            this -> array[start] = this -> array[end];
            this -> array[end] = temp;
        }
    }
    
    bool isSorted()
    {
        for(int i = 0; i < this -> length - 1; ++i)
            if (this -> array[i] > this -> array[i + 1])
                return false;
        
        return true;
    }
    
//    TODOs:
//    void rearrange() // rearrange +ve and -ve
//    void shifting left and right
//    rotate left and right
    
    ~NumbersArray()
    {
        delete []this -> array;
    }
};
