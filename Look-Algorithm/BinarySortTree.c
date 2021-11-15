#include<stdio.h>
#include<stdlib.h>

typedef struct BinarySortTree
{
    int data;
    struct BinarySortTree *lchild,*rchild;
    /* data */
}BiTNode,*BiTree;

int SearchBST(BiTree T,int key,BiTree f,BiTree *p)//f是T的双亲，p是为了查找成功后得到查找到的节点位置。
{
    if(!T)
    {
        *p=f;               //查找不成功后将当前指向双亲。
        return 0;
    }
    else if(key==T->data)
    {
        *p=T;               //查找成功后将指针指向当前节点。
        return 1;
    }
    else if(key<T->data)
        return SearchBST(T->lchild,key,T,p);
    else
        return SearchBST(T->rchild,key,T,p);
}

int InsertBST(BiTree *T,int key)
{
BiTree p,s;
if(!SearchBST(*T,key,NULL,&p))//查找不成功
{
    s=(BiTree)malloc(sizeof(BiTree));
    s->data=key;
    s->lchild=s->rchild=NULL;
    if(!p)
        *T=s;
    else if(key<p->data)
        p->lchild=s;
    else
        p->rchild=s;e
    return 1;
}
else
    return 0;

}

int Dlete(BiTree *p)
{
    BiTree q,s;
    if((*p)->lchild==NULL)
    {q=*p;*p=(*p)->rchild;free(q);}
    else if((*p)->rchild==NULL)
    {q=*p;*p=(*p)->lchild;free(q);}
    else
    {
        q=*p;
        s=(*p)->lchild;
        while(s->rchild)
        {
            q=s;
            s=s->rchild;
        }
        if(q!=*p)
            q->rchild=s->lchild;
        else
            q->lchild=s->lchild;
        free(s);
    }
    return 1;
}

int DeleteBST(BiTree *T,int key)
{
    if(!*T)
        return 0;
    else{
        if((*T)->data==key)
            return Delete(T);
        else if(key<(*T)->data)
            return DeleteBST(&(*T)->lchild,key);
        else    
            return DeleteBST(&(*T)->rchild,key);
    }
}


int main()
{

    system("pause");
    return 0;
}