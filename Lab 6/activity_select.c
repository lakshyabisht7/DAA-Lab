#include <stdio.h>
int main()
{
    int start[10] = {1,3,0,5,8,5,2,6,8,12};
    int finish[10] = {2,4,6,7,9,9,10,11,13,14};

    int i, j, temp;
    int lastFinish;

    for(i=0; i<9; i++)
    {
        for(j=0; j<9-i; j++)
        {
            if(finish[j] > finish[j+1])
            {
                temp = finish[j];
                finish[j] = finish[j+1];
                finish[j+1] = temp;

                temp=start[j];
                start[j] = start[j+1];
                start[j+1] = temp;
            }
        }
    }

    printf("Activities after arranging by finish time:\n");
    printf("Activity\tStart\tFinish\n");

    for(i=0; i<10; i++)
    printf("%d\t\t%d\t%d\n", (i+1), start[i], finish[i]);

    printf("\nSelected Activities:\n");

    printf("Activity 1 (%d,%d)\n", start[0], finish[0]);
    lastFinish = finish[0];

    for(i=1; i<10; i++)
    {
        if(start[i] >= lastFinish)
        {
            printf("Activity %d (%d,%d)\n", (i+1), start[i], finish[i]);
            lastFinish = finish[i];
        }
    }
    return 0;
}


