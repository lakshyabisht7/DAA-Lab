#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void insertionSort(int arr[],int n)
{
    int i,j,key;

    for(i=1; i<n; i++) 
    {
        key=arr[i];
        j=i-1;

        while(j>=0 && arr[j]>key) 
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void checkTime(int n)
{
    int arr[n], i;
    clock_t start, end;

    for(i=0; i<n; i++)
    arr[i]=rand()%1000;

    start=clock();
    insertionSort(arr,n);
    end=clock();

    printf("n = %d, Time taken = %f seconds\n", n,(double)(end-start) / CLOCKS_PER_SEC);
}

int main() 
{
    int arr[]={12,11,13,5,6};
    int i,n=5;

    srand(time(0));

    printf("Original array: ");
    for(i=0; i<n; i++)
    printf("%d ",arr[i]);

    insertionSort(arr,n);

    printf("\nSorted array: ");
    for(i=0; i<n; i++)
    printf("%d ",arr[i]);

    printf("\n\nTime Analysis:\n");
    checkTime(10);
    checkTime(100);
    checkTime(1000);

    return 0;
}














/*#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int n,i,j,key;
    clock_t start, end;

    srand(time(0));

    for(n=10; n<=1000; n=n*10)
    {
        int arr[n];

        for(i=0; i<n; i++)
        arr[i]=rand()%1000;

        start=clock();

        for(i=1; i<n; i++)
        {
            key=arr[i];
            j=i-1;

            while(j>=0 && arr[j]>key)
            {
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
        end=clock();

        printf("n = %d, Time taken = %f seconds\n",n,(double)(end-start) / CLOCKS_PER_SEC);
    }
    return 0;
}*/