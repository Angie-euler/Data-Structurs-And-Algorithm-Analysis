#include<stdio.h>
#include<stdlib.h>

void AdjustHeap(int *a,int s,int m)
{
    int temp,j;
    temp=a[s];
    for(j=2*s;j<m;j*=2)
    {
        if(j<m&&a[j]<a[j+1])
            ++j;
        if(temp>=a[j])
            break;
        a[s]=a[j];
        s=j;
    }
    a[s]=temp;
}


void HeapSort(int *a,int len)
{

int i,temp;
for(i=len/2;i>0;i--)
    AdjustHeap(a,i,len);
for(i=len;i>1;i--)
{
    temp=a[i];
    a[i]=a[1];
    a[1]=temp;
    AdjustHeap(a,1,i-1);
}

}




int main()
{
    int i,t[10]={0,10,8,20,6,3,66,13,9,15};
    HeapSort(t,9);
    for(i=1;i<10;i++)
    {
        printf("%d\t",t[i]);
    }
    //system("pause");
    return 0;
}