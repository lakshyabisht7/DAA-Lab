#include <stdio.h>

#define MAX 20

struct Node
{
    char ch;
    int freq;
    int left;
    int right;
    int used;
};

void printCodes(struct Node node[],int root,char code[],int top)
{
    if(node[root].left==-1 && node[root].right==-1)
    {
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
    struct Node node[2*MAX-1];
    int n,i,j,min1,min2,total;
    char code[MAX];

    printf("Enter number of characters: ");
    scanf("%d",&n);

    printf("Enter character and frequency:\n");

    for(i=0;i<n;i++)
    {
        scanf(" %c%d",&node[i].ch,&node[i].freq);

        node[i].left=-1;
        node[i].right=-1;
        node[i].used=0;
    }

    total=n;

    for(i=0;i<n-1;i++)
    {
        min1=-1;
        min2=-1;

        for(j=0;j<total;j++)
        {
            if(node[j].used==0)
            {
                if(min1==-1 || node[j].freq<node[min1].freq)
                {
                    min2=min1;
                    min1=j;
                }
                else if(min2==-1 || node[j].freq<node[min2].freq)
                {
                    min2=j;
                }
            }
        }

        node[min1].used=1;
        node[min2].used=1;

        node[total].ch='-';
        node[total].freq=node[min1].freq+node[min2].freq;
        node[total].left=min1;
        node[total].right=min2;
        node[total].used=0;

        total++;
    }

    printf("Huffman Codes:\n");

    if(n==1)
    {
        printf("%c : 0\n",node[0].ch);
    }
    else
    {
        printCodes(node,total-1,code,0);
    }

    return 0;
}