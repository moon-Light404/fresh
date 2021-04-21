#include "seqstack.h"
void init(sequence_stack *st)
{
    st->top = 0;
}

int empty(sequence_stack st)
{
    return (st.top ? 0 : 1);
}
// 读取栈头元素
datatype read(sequence_stack st)
{
    if(empty(st))
    {
        printf("\n栈是空的");
        exit(1);
    }
    else
        return st.a[st.top-1];
}
// 入栈
void push(sequence_stack *st,datatype x)
{
    if(st->top == MAXSIZE)
    {
        printf("\nThe sequence stack is full!");
        exit(1);
    }
    st->a[st->top] = x;
    st->top++;
}

// 出栈
void pop(sequence_stack *st)
{
    if(st->top == 0){
        printf("\nThe sequence stack is empty!");
        exit(1);
    }
    st->top--;

}