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
void enqueue(int val)
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
int dequeue()
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
int main()
{
       // cout<<"the value dequeued is "<<dequeue()<<endl;

   // linkedlist(f);
    enqueue(1);
    enqueue(2);
    enqueue(3);
    cout<<"the value dequeued is "<<dequeue()<<endl;
    linkedlist(f);
    return 0;
}