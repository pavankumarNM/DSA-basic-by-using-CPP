#include <stdio.h>
#include<stdlib.h>

struct stack
{
    int top;
    int size;
    char *arr;
};
int checkempty(struct stack* ptr)
{
    if (ptr->top== -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int checkfull(struct stack* ptr){
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

//
char pop(struct stack* ptr)
{
 if(checkempty(ptr)){
     printf("stack is underflow\n");
     return-1;
 }
 else{
     char val=ptr->arr[ptr->top];
     ptr->top--;
     return val;
 }
}
//
 void push(struct stack* ptr,char val)
{
    if(checkfull(ptr)){
        printf("stack overflow cannot push \n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }

}
//
int PM(char* exp)
{
    struct stack* sp;
    sp->size=20;
    sp->top=-1;
    sp->arr=(char*)malloc(sp->size*sizeof(char));
for (int i = 0; exp[i]!='\0'; i++)
{
    if (exp[i]=='(')
    {
        push(sp,'(');
    }
    else if(exp[i]==')'){
        if (checkempty(sp))
        {
            return 0;
        }
        
    pop(sp);
    }
    
}
if(checkempty(sp)){
    return 1;
}
else{
    return 0;
}

}

int main()
{
   
    char* exp="duhw)ei()0";     //I got a problem here in the c++ can't give a char pointer to a string in c++ go used in C
   if(PM(exp)){
       printf(" parenthes is matching\n");
   }
   else{
   printf("parenthes is not matching\n");
   }
    return 0;
}
