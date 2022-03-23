#include<stdio.h>

int Fibonacci(int n)
{
    if ( n == 0 )
        return 0;
    else if ( n == 1 )
        return 1;
    else
        return ( Fibonacci(n-1) + Fibonacci(n-2) );
} 

int main()
{
    int n, i = 0, c;
    printf("Enter number of terms for fibonacci series:");
    scanf("%d",&n);
    printf("Fibonacci series:\n");
    for ( c = 1 ; c <= n ; c++ )
    {
        printf("%d\n", Fibonacci(i));
        i++; 
    }
    return 0;
}