# include <stdlib.h>
#define True 1
#define False 0
//---------------------链表----------------------
typedef int bool;
typedef char ElemType;
/*链表的创建*/
typedef struct Lnode{
    ElemType data;
    struct Lnode *next;
}Lnode,*Linklist;
Linklist L;/*定义链表*/

/*生成头节点*/
void Initlist(Linklist *L){
    Linklist p;
    p=(Linklist)malloc(sizeof(L));
    p->next =NULL;
}

/*销毁链表*/
void DestroyList(Linklist *L)
{
    Linklist p;
    while(L){
        p=L;
        L=(*L)->next;
        free(p);
    }
}

/*清空单链表*/
void ClearList(Linklist *L)
{
    Linklist p,q;
    p=(*L)->next;
    while(p){
        q=p->next;
        free(p);
        p=q;
    }
    (*L)->next =NULL;
}

/*单链表表长*/
int ListLength(Linklist *L)
{
    int i=0;
    Linklist p;
    p=(*L)->next;
    while(p){
        i++;
        p=p->next;
    }
    return i;
}

/*获取第i个元素*/
ElemType GetData(Linklist *L, int i,ElemType *d)
{
    int j=1;
    Linklist p;
    p=(*L)->next;
    while(p&&j<i){
        p=p->next;
        j++;
    }
    if(!p||j>i){
        return NULL;
    }
    d=p->data;
    return d;
}

/*插入第i个位置的数据*/
void InsertLinklist(Linklist *L,int i,ElemType e)
{
    Linklist p;
    Linklist *s;
    (*s)->next=NULL;
    (*s)->data=e;
    int j=1;
    p=*L;
    while(p&&j<=(i-1)){ 
        p=p->next;
        j++;
    }
    if(!p||j>(i-1))
        return NULL;
    (*s)->next=p->next;
    p->next=(*s);
}

/*删除第i个位置的数据*/
void DeleteLinklist(Linklist *L,int i,ElemType *d)
{
    Linklist p,q;
    int j=1;
    p=*L;
    while(p&&j<=(i-1)){
        p=p->next;
        j++;
    }
    q=p->next;
    *d=q->data;
    p->next=p->next->next;
    free(q);
}

/*头插法建立链表*/
void HeadCreate(Linklist *L,ElemType *e,int n)
{
    Linklist p;
    int i,
    L=(Linklist)malloc(sizeof(Lnode));
    (*L)->next=NULL;
    for(i=0;i<n;i++){
        p=(Linklist *)malloc(sizeof(Lnode));
        p->data=(*e);
        p->next=(*L)->next;
        (*L)->next=p;
    }
}

/*尾插法建立链表*/
void TailCreate(Linklist *L,ElemType *e,int i)
{
    Linklist *r,p;
    p->data=(*e);
    p->next=NULL;
    L=(Linklist)malloc(sizeof(Lnode));
    (*L)->next=NULL;
    (*r)=L;
    for(i=0;i<10;i++){
        (*r)->next=p;
        (*r)=p;
    }
}
