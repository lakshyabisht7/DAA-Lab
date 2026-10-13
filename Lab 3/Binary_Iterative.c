#include <stdio.h>
int BinarySearch(int arr[],int n,int key) {
    int low=0, high=n-1;

    while(low <= high) {
        int mid = low+(high-low)/2;

        if(arr[mid] == key)
        return mid;

        else if(arr[mid] < key)
        low=mid+1;
        
        else
        high=mid-1;}
    return -1;}

int main() {
    int n,key;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n];

    printf("Enter %d elements in sorted order:\n",n);
    for(int i=0; i<n; i++)
    scanf("%d",&arr[i]);

    printf("Enter element to search: ");
    scanf("%d",&key);
    int result = BinarySearch(arr,n,key);

    if(result != -1)
    printf("Element found at index: %d",result);

    else
    printf("Element not found");
    return 0;}