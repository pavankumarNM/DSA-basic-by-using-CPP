#include <iostream>
#include <stdlib.h>
using namespace std;
struct stack
{
    int size;
    int top;
    int *arr;
};
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        cout << "stack overflow   cannot push value  " << val << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "stack overflow   cannot pop value  " << endl;
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(struct stack *ptr, int i)
{
    int arrind = ptr->top - i + 1;
    if (arrind < 0)
    {
        cout << "the stack is empty";
        return -1;
    }
    else
    {
        return ptr->arr[arrind];
    }
}
int stackbottom(struct stack* ptr){
    return ptr->arr[0];
}
int stacktop(struct stack* ptr){
    return ptr->arr[ptr->top];
}
int main()
{
    struct stack *sp;
    sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    cout << "stack has been created successfully " << endl;
    cout << "before push if empty  " << isEmpty(sp) << endl;
    cout << "before push if full " << isFull(sp) << endl;

    push(sp, 1);
    push(sp, 2);
    push(sp, 3);
    push(sp, 4);
    push(sp, 56);

    // cout<<"after push if empty  "<<isEmpty(sp)<<endl;
    // cout<<"after push if full "<<isFull(sp)<<endl;
    // cout<<"popped "<<pop(sp)<<" from the stack"<<endl;
    //     cout<<"popped "<<pop(sp)<<" from the stack"<<endl;
    // for (int j= 1; j <= sp->top+1; j++)
    //   {
    //         cout<<"the value at index "<<j<<" is "<<peek(sp,j)<<endl;

    //   }
    //cout << "the value at index  2 is " << peek(sp, 2) << endl;
   cout<<"the bottom value of the stack is "<<stackbottom(sp)<<endl;
     cout<<"the top value of the stack is "<<stacktop(sp)<<endl;
   
    
    return 0;
}