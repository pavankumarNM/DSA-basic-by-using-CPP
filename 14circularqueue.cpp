#include <iostream>
#include <stdlib.h>
using namespace std;
struct queue
{
    int F;
    int R;
    int size;
    int *arr;
};
void Displayqueue(struct queue *ptr)
{
    cout << "displaying queue" << endl;
    int j = 0;
    for (int i = ptr->F+1; i <=ptr->R; i++)
    {
        cout << " the element at index " << j << " : " << ptr->arr[i] << endl;
        j++;
    }
}
void enqueue(struct queue *ptr, int val)
{
    if ((ptr->R + 1) % ptr->size == ptr->F)
    {
        cout << "queue overflow" << endl;
    }
    else
    {
        ptr->R = (ptr->R + 1) % ptr->size;

        ptr->arr[ptr->R] = val;
    }
}
int dequeue(struct queue *ptr)
{
    if ((ptr->F + 1) % ptr->size == ptr->R)
    {
        cout << "queue underflow" << endl;
    }
    else
    {
        int a = -1;

        ptr->F = (ptr->F + 1) % ptr->size;
        a = ptr->arr[ptr->F];
        return a;
    }
}
int main()
{

    struct queue Q;
    Q.size = 6;
    Q.F = 0;
    Q.R = 0;
    Q.arr = (int *)malloc(Q.size * sizeof(int));
    enqueue(&Q, 1);
    enqueue(&Q, 2);
    enqueue(&Q, 3);
    enqueue(&Q, 4);
    enqueue(&Q, 5);
    enqueue(&Q, 6);
   // cout << "the value dequeued is " << dequeue(&Q) << endl;
    enqueue(&Q, 7);
    // cout<<"the value dequeued is "<<dequeue(&Q)<<endl;
    //   cout<<"the value dequeued is "<<dequeue(&Q)<<endl;
    //     cout<<"the value dequeued is "<<dequeue(&Q)<<endl;
    //       cout<<"the value dequeued is "<<dequeue(&Q)<<endl;
    cout << "the value dequeued is " << dequeue(&Q) << endl;
    cout << "the value dequeued is " << dequeue(&Q) << endl;
    //  cout << "the value dequeued is " << dequeue(&Q) << endl;
    // cout << "the value dequeued is " << dequeue(&Q) << endl;
    //  cout << "the value dequeued is " << dequeue(&Q) << endl;
    // cout << "the value dequeued is " << dequeue(&Q) << endl;

    Displayqueue(&Q);
    return 0;
}