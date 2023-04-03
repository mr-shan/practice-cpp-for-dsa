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

// recursive function for getting combination of numbers.
// the original formula for getting combination is:
// nCr = n! / (r! * (n - r)!)
// the below function make use of PASCAL's triangle to find the combination
// pascal's triangle reference: https://en.wikipedia.org/wiki/Pascal%27s_triangle
int nCr(int n, int r) {
    if (n == r || r == 0) return 1;
    
    return nCr(n-1, r-1) + nCr(n-1, r);
}

// using formula
// nCr = n! / (r! * (n - r)!)
int nCr2(int n, int r) {
    int factN = factorial(n);
    int factR = factorial(r);
    int factNminusR = factorial(n - r);
    
    return factN / (factR * factNminusR);
}


int main()
{
    int num = 6, power = 3;
    int n = 4, r = 2;       // for the nCr combination function
    printf("Factorial of %d is: %d\n", num, factorial(num));
    printf("Sum of all numbers till %d is: %d\n", num, sumOfNumbers(num));
    printf("The power of %d to %d is: %d\n", num, power, exponent(num, power));
    printf("The %d term in fibonacci series is %d\n", num, mFibonacci(num));
    printf("Combination of %d at %d is: %d\n", n , r, nCr(n, r));
    
    return 0;
}
