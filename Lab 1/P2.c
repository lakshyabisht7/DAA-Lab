#include <stdio.h>
int main()
{
    int arr[100], n, i; 
    float avg=0.0f, sum=0.0f;

    printf("Enter the no. of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i=0; i<n; i++)
    scanf("%d", &arr[i]);
    
    for(i=0; i<n; i++)
    sum+=arr[i];

    avg=sum/n;

    printf("Sum of all elements: %f\n", sum);
    printf("Average of all elements: %f", avg);

    return 0;
}
