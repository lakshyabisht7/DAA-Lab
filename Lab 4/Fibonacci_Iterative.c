#include <stdio.h>

void fibo_Iterative(int n) {
    int a=0, b=1, s;
    printf("Iterative Fibonacci Series: ");

    for(int i=0; i<n; i++) 
    {
        printf("%d ",a);
        s = a+b;
        a = b;
        b = s;
    }
    printf("\n");
}

int main() 
{
    int n;
    printf("Enter number of terms: ");
    scanf("%d",&n);
    fibo_Iterative(n);
    return 0;
}



