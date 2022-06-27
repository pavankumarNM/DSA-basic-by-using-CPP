#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct stack *ptr)            //looks tough it is but once u become champion u can defeat the defeat before it defeats u :)
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
void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("stack overflow   cannot push %d  ", val);
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
        printf("stack overflow   cannot pop value  ");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int isoperator(char val)
{
    if (val == '*' || val == '/' || val == '-' || val == '+')
    {
        return 1;
    }

    else
    {
        return 0;
    }
}
int pred(char val)
{
    if (val == '*' || val == '/')
    {
        return 3;
    }
    else if (val == '+' || val == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
char *ITP(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 500;
    sp->top = -1;
    int i = 0;
    int j = 0;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc(strlen(infix + 1) * sizeof(char));
    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (!isoperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {

            if (pred(infix[i]) > pred(sp->arr[sp->top]))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }

    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    // postfix[j]='\0';
    return postfix;
}
int main()
{
    char *infix = "a-b";
    printf("the value of postfix is %s", ITP(infix));
    return 0;
}