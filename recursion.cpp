#include <stdio.h>
#include <stdlib.h>

// tail recursion. 
// the recursive call is the LAST STATEMENT in the recursive function
// all the operations are performed at calling time and no execution at returning time.
int factorial(int num) {
    if (num == 0) return 1;
    return num * factorial(num - 1);
}

// head recursion.
// the recursive call is the FIRST STATEMENT in the recursive function
// all the operations are performed at the returning time and nothing gets executed at calling time.
int sumOfNumbers(int num) {
    if (num == 0) return 0;
    return sumOfNumbers(num - 1) + num;
}

// this recursion runs at value of power times to calculate exponent.
// this also involves the mutlitplication at power times.
int exponent(int num, int power) {
    if (power == 0) return 1;
    return num * exponent(num, power - 1);
}

// optmized version of exponent function.
int power1(int m,int n)
{
    if (n == 0) return 1;
    if (n % 2 == 0) return power1(m * m, n / 2);
    return m * power1 (m * m, (n - 1) / 2);
}

// regular function for fibonacci series
int fibonacci(int num) 
{
    if (num <= 1) return num;
    
    return fibonacci(num - 2) + fibonacci(num - 1);
}

int fibArray[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
// fibonacci function using memoization
int mFibonacci(int num)
{
    if (num <= 1) {
        fibArray[num] = num;
        return num;
    }
    
    if (fibArray[num - 2] == -1)
        fibArray[num - 2] = mFibonacci(num - 2);
            
    if (fibArray[num - 1] == -1)
        fibArray[num - 1] = mFibonacci(num - 1);
    
    return fibArray[num - 2] + fibArray[num - 1];
}


int main()
{
    int num = 6, power = 3;
    printf("Factorial of %d is: %d\n", num, factorial(num));
    printf("Sum of all numbers till %d is: %d\n", num, sumOfNumbers(num));
    printf("The power of %d to %d is: %d\n", num, power, exponent(num, power));
    printf("The %d term in fibonacci series is %d\n", num, mFibonacci(num));
    
    return 0;
}
