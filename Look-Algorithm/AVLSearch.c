#include<stdio.h>
#include<stdlib.h>
#define LH 1;
#define EH 0;
#define RH -1;

typedef struct BiNode
{
    int data;
    int bf;//平衡因子。
    struct BiNode *lchiled,*rchild;
}BiNode,*BiTree;

void R_Rotate(BiTree *p)//右旋转
{
    BiTree L;
    L=(*p)->lchiled;
    (*p)->lchiled=L->rchild;
    L->rchild=*p;
    *p=L;
}

void L_Rotate(BiTree *p)//左旋转
{
    BiTree R;
    R=(*p)->rchild;
    (*p)->rchild=R->lchiled;
    R->lchiled=*p;
    *p=R;
}

void LeftBalance(BiTree *T)
{
    BiTree L Lr;
    L=(*T)->lchiled;
    switch(L->bf)
    {
        case LH:
            (*T)->bf=L->bf=EH;
            R_Rotate(T);
            break;
        case RH:
            Lr=(*T)->rchild;
            switch(Lr->bf)
            {
                case LH:
                    (*T)->bf=RH;
                    L->bf=EH;
                    break;
                case EH:
                    (*T)->bf=EH;
                    L->bf=EH;
                    break;                
                case RH:
                    (*T)->bf=EH;
                    L->bf=LH;
                    break;
            }
            Lr->bf=EH;
            L_Rotate(&(*T)->lchiled);
            R_Rotate(T);
    }

}

void RightBalance(BiTree *T)
{
    BiTree R,Rl;
    R=(*T)->lchiled;
    switch (R->bf)
    {
        case LH:
            Rl=R->lchiled;
            switch(Rl->bf)
            {
                case LH:
                    (*T)->bf=EH;
                    R->bf=RH;
                    break;
                case EH:
                    (*T)->bf=R->bf;
                    break;
                case RH;
                    (*T)->bf=LH;
                    R->bf=EH;
                    break;
            }
            Rl->bf=EH;
            R_Rotate(&(*T)->rchild);
            L_Rotate(T);
            break;
        case RH:
            (*T)->bf=R->bf=EH;
            L_Rotate(T);

    }
}

int InsertAVL(BiTree *T,int key,int *t)
{
    if(!*T)
    {
        *T=(BiTree)malloc(sizeof(BiNode));
        (*T)->data=key;
        (*T)->lchiled=(*T)->rchild=NULL;
        (*T)->bf=EH;
    }
    else 
    {
        if((*T)->data==key)
        {
        *t=0;
        return 0;
        }
        if(key<(*T)->data)
        {
            if(!InsertAVL(&(*T)->lchiled),key,t)
                retuen 0;
            if(t)
            {
                switch((*T)->bf)
                {
                    case LH:
                        LeftBalance(T);
                        t=0;
                        break;
                    case EH:
                        (*T)->bf=LH;
                        t=1;
                        break;
                    case RH:
                        (*T)->bf=EH;
                        t=0;
                        break;
                }
            }
        }
        else
        {
            if(!InsertAVL(&(*T)->rchiled),key,t)
                retuen 0;
            if(t)
            {
                switch((*T)->bf)
                {
                    case LH:
                        (*T)->bf=EH;
                        t=0;
                        break;
                    case EH:
                        (*T)->bf=RH;
                        t=1;
                        break;
                    case RH:
                        RightBalance(&(*T)->rchild,key,t);
                        t=0;
                        break;
                }
            }
        }
    }


}

int main()
{

    return 0;
}
