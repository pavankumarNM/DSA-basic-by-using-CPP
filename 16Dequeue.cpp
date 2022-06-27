#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
struct node *f = NULL;
struct node *r = NULL;
void linkedlist(struct node *ptr)
{
    cout << "printing the linkedlist" << endl;
    while (ptr != NULL)
    {
        cout << "element : " << ptr->data << endl;
        ptr = ptr->next;
    }
}
void Rearenqueue(int val)
{ 
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        cout << "node is full" << endl;
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }

        r->next = n;
        r = n;
    }
}
int Frontdequeue()
{ 
    struct node *ptr = f;
    int val = -1;
    if (f == NULL)
    {
        cout << "node is empty" << endl;
    }
    else
    {

        val = ptr->data;
        f = f->next;
        free(ptr);
    }
    return val;
}
int Reardequeue()
{int val=-1;
      struct node* p;
      struct node* q=f;
     p=q->next;
    
    while(p->next!=NULL){
        q=q->next;
        p=p->next;
        
    }
    q->next=NULL;
    val=p->data;
    free(p);
    
   return val;
}
void Frontenqueue(int val){
   struct node* ptr=(struct node*)malloc(sizeof(struct node));
   ptr->data=val;
   ptr->next=f;
   f=ptr;
}
int main()
{
    // cout<<"the value dequeued is "<<dequeue()<<endl;

    // linkedlist(f);
    Rearenqueue(1);
    Rearenqueue(2);
    Rearenqueue(3);
    Rearenqueue(4);
    Rearenqueue(5);
    Rearenqueue(6);
    Rearenqueue(7);
    Rearenqueue(8);
    Rearenqueue(9);
    Rearenqueue(10);
    Rearenqueue(11);
    cout << "the value dequeued is " << Frontdequeue() << endl;
    linkedlist(f);
    cout << "the value dequeued from rear  is " << Reardequeue() << endl;
    linkedlist(f);
    Frontenqueue(0);
    linkedlist(f);
    // at last i got this thing 
    return 0;
}
