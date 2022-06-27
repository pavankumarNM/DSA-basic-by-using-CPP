#include <iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
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
     cout<<"stack is underflow"<<endl;
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
        cout<<"stack overflow cannot push "<<val<<endl;
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }

}
//
int PM(string** exp)
{
    struct stack* sp;
    sp->size=20;sp->top=-1;
    sp->arr=(string*)malloc(sp->size*sizeof(char));
for (int i = 0; exp[i]!='\0'; i++)
{
    if ((*exp[i])=='(')
    {
        push(sp,'(');
    }
    else if((*exp[i])==')'){
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
   
    //string* exp="duhwe)i(0";              //I got a problem here in the c++ can't give a char pointer to a string in c++ go used in C check that out 
      string e="pava90()";string*exp=&e;
      cout<<*exp;
   if(PM(exp)){
       cout<<" parenthesis matching"<<endl;
   }
   else{
   cout<<"parenthesis not matching"<<endl;
   }
    return 0;
}

// fucking hard to write this code don't know what happened i think need to concentrate on the alogorithms before writing code ie : pseudocode


//multiple parenthesis matching   i am not gonna solve the that fucking problem