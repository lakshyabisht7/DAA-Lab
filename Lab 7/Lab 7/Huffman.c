
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define SIZE (2*MAX-1)

struct Node
{
    char ch;
    int freq;
    int left;
    int right;
};

struct MinHeap
{
    int data[SIZE];
    int size;
};

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void insert(struct MinHeap *h,int index,struct Node node[])
{
    int i=h->size;
    int parent;

    h->data[h->size]=index;
    h->size++;

    while(i>0)
    {
        parent=(i-1)/2;

        if(node[h->data[parent]].freq<=node[h->data[i]].freq)
            break;

        swap(&h->data[parent],&h->data[i]);
        i=parent;
    }
}

int extractMin(struct MinHeap *h,struct Node node[])
{
    int min=h->data[0];
    int i=0,left,right,small;

    h->size--;
    h->data[0]=h->data[h->size];

    while(2*i+1<h->size)
    {
        left=2*i+1;
        right=2*i+2;
        small=left;

        if(right<h->size && node[h->data[right]].freq<node[h->data[left]].freq)
            small=right;

        if(node[h->data[i]].freq<=node[h->data[small]].freq)
            break;

        swap(&h->data[i],&h->data[small]);
        i=small;
    }

    return min;
}

void printCodes(struct Node node[],int root,char code[],int top)
{
    if(node[root].left==-1 && node[root].right==-1)
    {
        if(top==0)
            code[top++]='0';

        code[top]='\0';
        printf("%c : %s\n",node[root].ch,code);
        return;
    }

    code[top]='0';
    printCodes(node,node[root].left,code,top+1);

    code[top]='1';
    printCodes(node,node[root].right,code,top+1);
}

int main()
{
    struct Node node[SIZE];
    struct MinHeap h;
    int n,i,left,right,total,choice;
    char code[MAX];

    h.size=0;
    srand((unsigned int)time(NULL));

    printf("Enter number of characters (1-100): ");

    if(scanf("%d",&n)!=1 || n<1 || n>MAX)
    {
        printf("Invalid number of characters.\n");
        return 0;
    }

    printf("1. Manual frequencies\n");
    printf("2. Random frequencies\n");
    printf("Enter choice: ");

    if(scanf("%d",&choice)!=1 || (choice!=1 && choice!=2))
    {
        printf("Invalid choice.\n");
        return 0;
    }

    if(choice==1)
    {
        printf("Enter each character and its frequency:\n");

        for(i=0;i<n;i++)
        {
            if(scanf(" %c%d",&node[i].ch,&node[i].freq)!=2 || node[i].freq<=0)
            {
                printf("Invalid character or frequency.\n");
                return 0;
            }
        }
    }
    else
    {
        printf("Generated characters and frequencies:\n");

        for(i=0;i<n;i++)
        {
            node[i].ch='A'+i;
            node[i].freq=1+rand()%100;

            printf("%c : %d\n",node[i].ch,node[i].freq);
        }
    }

    for(i=0;i<n;i++)
    {
        node[i].left=-1;
        node[i].right=-1;
        insert(&h,i,node);
    }

    total=n;

    while(h.size>1)
    {
        left=extractMin(&h,node);
        right=extractMin(&h,node);

        node[total].ch='-';
        node[total].freq=node[left].freq+node[right].freq;
        node[total].left=left;
        node[total].right=right;

        insert(&h,total,node);
        total++;
    }

    printf("Huffman Codes:\n");
    printCodes(node,h.data[0],code,0);

    return 0;
}
