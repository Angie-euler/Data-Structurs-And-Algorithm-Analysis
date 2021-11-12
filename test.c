#include<stdio.h>
#define MIN(a,b) (a<b)?a:b 
void swap(int c,int d)
{
int tp;
tp=c;
c=d;
d=tp;
}
int main()
{
    //char str[]="Welcome to NKET";
    //int x,i,j,k;
    //x=(i=4,j=32,k=66);
    //int a[2][2]={{1},{2,3}};
   // a[0]=0;a[1]=1;a[2]=2;
    //int *q,*p;
    //p=a;
    //q=&a[2];
    //temp=q-p;

    //static int a=2,b=6;
 /*   int d=3;
    const int *a=&d,b=4,c=6;
    a=&b;
    printf("%d\n",a);
    printf("%d\n",*a);
    a=&c;
    printf("%d\n",a);
    printf("%d\n",*a);*/


    system("pause");
    return 0;
}


/*
#include <stdio.h>

#define MAXLEN (int)20
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) (a<b)?a:b

int main(void)
{
    int a[MAXLEN];
    int i,maxvalue,minvalue;

    srand(0x45623);
    for(i = 0; i < MAXLEN; i++)
        printf("%d ",a[i] = rand());

    maxvalue =minvalue = a[0];
    for(i = 1; i < MAXLEN; i++)
    {
         maxvalue = MAX(maxvalue, a[i]);
         minvalue =  MIN(minvalue , a[i]);
    }

    printf("/nMaxValue = %d/nMinValue = %d/n",maxvalue,minvalue);

    return 1;
}
*/