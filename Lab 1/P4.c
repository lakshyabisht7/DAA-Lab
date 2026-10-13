#include <stdio.h>
int main()
{
    int arr[100],n,i;

    printf("Enter the no. of elements:");
    scanf("%d",&n);

    printf("Enter %d elements: \n",n);
    for(i=0; i<n; i++)
    scanf("%d",&arr[i]);
    
    int temp=0;

    for(i=0; i<n/2; i++)
    {
        temp=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=temp;
    }

    printf("Reversed array:");
    for(i=0; i<n; i++)
    printf("%d ",arr[i]);

    return 0;
}
