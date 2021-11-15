#include<stdio.h>
void BubbleSort(int *t,int length);
int main()
{
    int i,t[10]={10,20,3,6,8,66,12,9,15,2};
    BubbleSort(t,10);
    for(i=0;i<=10;i++)
    {
        printf("%d\n",t[i]);
    }
    system("pause");
    return 0;
}

void BubbleSort(int *t,int length)
{

    int i,j,temp;
    for(i=0;i<=length;i++)
    {
        for(j=i+1;j<=length;j++)
        {
            if(t[i]>t[j])
            {
                temp=t[i];
                t[i]=t[j];
                t[j]=temp;
            }
        }
    }
}

