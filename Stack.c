# include <stdio.h>
# include <stdlib.h>
# define STACK_INIT_SIZE 100
# define STACKINCREMENT  10

typedef char Elemtype;
typedef struct{
    Elemtype *base;
    Elemtype *top;
    int stacksize;
}sqStack;
//----------创建一个栈-----------
initStack (sqStack *s)
{
    //----------声明栈底--------------
    s->base=(Elemtype *)malloc((STACK_INIT_SIZE)*sizeof(Elemtype));
    //----------基础条件判断-----------
    if(!s->base){
        exit(0);
    }
    s->top=s->base;//给top指针赋值
    s->stacksize=STACK_INIT_SIZE;
}
//---------压栈操作--------
Push(sqStack *s,Elemtype e)
{
    if(s->top - s->base >= s->stacksize){
        s->base = (Elemtype*)realloc(s->base,(s->stacksize+STACKINCREMENT)*sizeof(Elemtype));
        if (!s->base){
            exit(0);
        }
        s->top=s->base +s->stacksize;
        s->stacksize=STACK_INIT_SIZE+STACKINCREMENT;
    }
    *(s->top)=e;
    s->top++;
}
//---------弹栈操作---------
Pop(sqStack *s, Elemtype e)
{
    if(!(s->top-s->base)){
        exit(0);
    }
    s->top--;
    e=*(s->top);
}
