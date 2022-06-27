#include<iostream>
#include<stdlib.h>
using namespace std;
struct stack {
int *arr;
int top;
int size;
};
int checkfull(struct stack* ptr){
if(ptr->top==ptr->size-1){
    return 1;
}
else
{
    return 0;
}

}
int checkempty(struct stack* ptr){
   if(ptr->top==-1){
     return 1;
}
else
{ 
     return 0;
}
 
}

int main(){
    struct stack* s;
    s->size=20;
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));
   
    if(checkfull(s)){
        cout<<"the stack is full,  ";
    
    }
    else
    {
        cout<<"the stack is not full,  ";  
    }
    if(checkempty(s)){
        cout<<"the stack is empty,  ";  
    }
    else
    {
        cout<<"the stack is not empty,   ";  
    }
    
    return 0;
}



//something error is there but i can't figure it out