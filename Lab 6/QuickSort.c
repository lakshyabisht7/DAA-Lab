#include <stdio.h>
int partition(int a[],int low,int high)
{
    int pivot = a[low];
    int i = low;
    int j = high;
    int temp;

    while(i<j)
    {
        while(a[i]<=pivot && i<high)
        i++;

        while (a[j]>pivot)
        j--;
        

        if(i<j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quickSort(int a[],int low,int high)
{
    if(low<high)
    {
        int p = partition(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
}

int main()
{
    int a[] = {2,3,9,0,-2,30,40,-40,5,45};
    int n=10;
    int i;

    printf("Original array:\n");

    for(i=0; i<n; i++)
    printf("%d ",a[i]);

    quickSort(a,0,n-1);

    printf("\nSorted array:\n");

    for(i=0; i<n; i++)
    printf("%d ",a[i]);

    return 0;
}


