
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 32

void add(int n,int a[MAX][MAX],int b[MAX][MAX],int c[MAX][MAX])
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
}

void sub(int n,int a[MAX][MAX],int b[MAX][MAX],int c[MAX][MAX])
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            c[i][j]=a[i][j]-b[i][j];
        }
    }
}

void strassen(int n,int a[MAX][MAX],int b[MAX][MAX],int c[MAX][MAX])
{
    int i,j,k;
    int a11[MAX][MAX],a12[MAX][MAX],a21[MAX][MAX],a22[MAX][MAX];
    int b11[MAX][MAX],b12[MAX][MAX],b21[MAX][MAX],b22[MAX][MAX];
    int p1[MAX][MAX],p2[MAX][MAX],p3[MAX][MAX],p4[MAX][MAX];
    int p5[MAX][MAX],p6[MAX][MAX],p7[MAX][MAX];
    int x[MAX][MAX],y[MAX][MAX];
    int c11[MAX][MAX],c12[MAX][MAX],c21[MAX][MAX],c22[MAX][MAX];

    if(n==1)
    {
        c[0][0]=a[0][0]*b[0][0];
        return;
    }

    k=n/2;

    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++)
        {
            a11[i][j]=a[i][j];
            a12[i][j]=a[i][j+k];
            a21[i][j]=a[i+k][j];
            a22[i][j]=a[i+k][j+k];

            b11[i][j]=b[i][j];
            b12[i][j]=b[i][j+k];
            b21[i][j]=b[i+k][j];
            b22[i][j]=b[i+k][j+k];
        }
    }

    sub(k,b12,b22,x);
    strassen(k,a11,x,p1);

    add(k,a11,a12,x);
    strassen(k,x,b22,p2);

    add(k,a21,a22,x);
    strassen(k,x,b11,p3);

    sub(k,b21,b11,x);
    strassen(k,a22,x,p4);

    add(k,a11,a22,x);
    add(k,b11,b22,y);
    strassen(k,x,y,p5);

    sub(k,a12,a22,x);
    add(k,b21,b22,y);
    strassen(k,x,y,p6);

    sub(k,a11,a21,x);
    add(k,b11,b12,y);
    strassen(k,x,y,p7);

    add(k,p5,p4,x);
    sub(k,x,p2,y);
    add(k,y,p6,c11);

    add(k,p1,p2,c12);
    add(k,p3,p4,c21);

    add(k,p5,p1,x);
    sub(k,x,p3,y);
    sub(k,y,p7,c22);

    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++)
        {
            c[i][j]=c11[i][j];
            c[i][j+k]=c12[i][j];
            c[i+k][j]=c21[i][j];
            c[i+k][j+k]=c22[i][j];
        }
    }
}

int main()
{
    int a[MAX][MAX]={0},b[MAX][MAX]={0},c[MAX][MAX]={0};
    int n,m=1,i,j,choice;

    srand((unsigned int)time(NULL));

    printf("Enter order of matrices (1-32): ");
    if(scanf("%d",&n)!=1 || n<1 || n>MAX)
    {
        printf("Invalid matrix order.\n");
        return 0;
    }

    printf("1. Manual input\n");
    printf("2. Random input\n");
    printf("Enter choice: ");
    if(scanf("%d",&choice)!=1 || (choice!=1 && choice!=2))
    {
        printf("Invalid choice.\n");
        return 0;
    }

    while(m<n)
    {
        m=m*2;
    }

    if(choice==1)
    {
        printf("Enter first matrix:\n");

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }

        printf("Enter second matrix:\n");

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&b[i][j]);
            }
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                a[i][j]=rand()%10;
                b[i][j]=rand()%10;
            }
        }

        printf("Randomly generated matrices:\n");

        printf("Matrix A:\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                printf("%d\t",a[i][j]);

            printf("\n");
        }

        printf("Matrix B:\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                printf("%d\t",b[i][j]);

            printf("\n");
        }
    }

    strassen(m,a,b,c);

    printf("Resultant matrix:\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d\t",c[i][j]);

        printf("\n");
    }

    return 0;
}