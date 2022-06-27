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
    for (int i = ptr->F + 1; i <= ptr->R; i++)
    {
        cout << " the element at index " << j << " : " << ptr->arr[i] << endl;
        j++;
    }
}
int checkfull(struct queue *ptr)
{
    if (ptr->R == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int checkempty(struct queue *ptr)
{
    if (ptr->F == ptr->R)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct queue *ptr, int val)
{
    if (checkfull(ptr))
    {
        cout << "queue full" << endl;
    }
    else
    {
        ptr->R++;
        ptr->arr[ptr->R] = val;
    }
}
int dequeue(struct queue *ptr)
{
    if (checkempty(ptr))
    {
        cout << "queue empty" << endl;
    }
    else
    {
        int a = -1;
        ptr->F++;
        a = ptr->arr[ptr->F];
        return a;
    }
}
int main()
{

    struct queue Q;
    Q.size = 50;
    Q.F = -1;
    Q.R = -1;
    Q.arr = (int *)malloc(Q.size * sizeof(int));

    //     enqueue(&Q,1);
    //     enqueue(&Q,2);
    //     // enqueue(&Q,3);
    //     //  enqueue(&Q,4);
    //     //   enqueue(&Q,5);
    //     //    enqueue(&Q,5);
    //     Displayqueue(&Q);
    //     cout<<"the value dequeued is "<<dequeue(&Q)<<endl;
    //     cout<<"the value dequeued is "<<dequeue(&Q)<<endl;
    //      cout<<"the value dequeued is "<<dequeue(&Q)<<endl;
    // //Displayqueue(&Q);



// finally finally finally finally finally finally finally finally