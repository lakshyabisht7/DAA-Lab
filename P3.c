#include <stdio.h>
int main()
{
    int arr[100],n,i,l;

    printf("Enter the number of elements: ");
    scanf("%d",&n);

    printf("Enter %d elements: \n",n);
    for(i=0; i<n; i++)
    scanf("%d", &arr[i]);

    l=arr[0];

    for(i=1; i<n; i++)
    {
        if(arr[i] > l)
        l=arr[i];
    }

    printf("Largest element=%d\n", l);

    return 0;
}