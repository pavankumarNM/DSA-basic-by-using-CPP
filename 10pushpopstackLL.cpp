#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
void LLtraversal(struct Node *ptr)
{
    cout << "  stack is " << endl;
    while (ptr != NULL)
    {
        cout << "element is : " << ptr->data << endl;
        ptr = ptr->next;
    }
}
int isempty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int checkFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct Node *push(struct Node *top, int data)
{
    // if(checkFull){
    //     cout<<"stack overflow"<<endl;
    // }
    // else{
    cout << "element pushed is " << data << endl;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = top;
    top = ptr;
    return top;
    // }
}
struct Node *pop(struct Node *top)
{
    cout << "the element popped is " << top->data << endl;
    struct Node *ptr = top;
    top = top->next;
    free(ptr);
    // cout<<"ptr data is "<<ptr->data;     // used just to check if the free function worls or not
    return top;
}
int peek(struct Node* top,int index){
    struct Node* ptr=top;int i=0;
    for (; i<index; i++)
    {
        cout<<"at index "<<i<<"  the value is "<<ptr->data<<endl;
        ptr=ptr->next; 
    }
    //  if(i==index){
    //     // cout<<index<<endl;
    //     return ptr->data;                                     // its getting fucking complicated so better to get watched the game
    // }
    
    
}
int stackbottom(struct Node *top){
 for (int i = 0; top->next!=NULL ; i++)
 {
     top=top->next;
 }
 return top->data;
}
int stackup(struct Node *top){
    cout<<endl;
    return top->data;
}


int main()
{
    struct Node *top = NULL;
    top = push(top, 111);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);
    top = push(top, 5);
    top = pop(top);
    
    LLtraversal(top);
    peek(top,4);
    cout<<" the stackbottom is "<<stackbottom(top);
    cout<<" the stacktop is "<<stackup(top);
    return 0;
}