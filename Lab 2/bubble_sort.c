#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
 
void bubbleSort(int arr[],int n) { 
    int i,j,temp,swapped; 
 
    for(i=0; i<n-1; i++)  { 
        swapped=0; 
 
        for(j=0; j<n-i-1; j++)  { 
            if(arr[j]>arr[j+1])  { 
                temp=arr[j]; 
                arr[j]=arr[j+1]; 
                arr[j+1]=temp; 
                swapped=1; 
            } 
        } 
        if(swapped==0) 
        break; 
    } 
} 
 
void checkTime(int n) { 
    int arr[n], i; 
    clock_t start, end; 
 
    for(i=0; i<n; i++) 
    arr[i]=rand()%1000; 
 
    start=clock(); 
    bubbleSort(arr,n); 
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
 
    bubbleSort(arr,n); 
 
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
void bubbleSort(int arr[],int n)
{
    int i,j,temp,swapped;

    for(i=0; i<n-1; i++)
    {
        swapped=0;
        for(j=0; j<n-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped=1;}
        }
        if(swapped==0)
        break;
    }
}

void printArray(int arr[],int n)
{
    int i;
    for(i=0; i<n; i++)
    printf("%d ",arr[i]);
    
    printf("\n");
}
int main()
{
    int arr[]={5,2,4,6,1,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Before sorting: ");
    printArray(arr,n);

    bubbleSort(arr,n);

    printf("After sorting: ");
    printArray(arr,n);

    return 0;
}*/