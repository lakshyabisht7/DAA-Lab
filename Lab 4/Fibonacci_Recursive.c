#include <stdio.h>

int fibo_Recursive(int n) 
{
    if(n==0 || n==1)
    return n;

    else
    return fibo_Recursive(n-1) + fibo_Recursive(n-2);
}

int main() 
{
    int n;
    printf("Enter number of terms: ");
    scanf("%d",&n);

    printf("Recursive Fibonacci Series: ");
    for (int i=0; i<n; i++)
    printf("%d ",fibo_Recursive(i));
    
    return 0;
}

