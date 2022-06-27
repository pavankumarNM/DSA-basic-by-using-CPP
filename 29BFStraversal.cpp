#include <iostream>
using namespace std;
struct queue
{
    int *arr;
    int F;
    int R;
    int size;
};
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
int enqueue(struct queue *ptr, int val)
{
    if (checkfull(ptr))
    {
        cout << "queue is full" << endl;
        return -1;
    }
    ptr->R++;
    ptr->arr[ptr->R] = val;
}
int dequeue(struct queue *ptr)
{
    int a = -1;
    if (checkempty(ptr))
    {
        cout << "the queue is empty" << endl;
        return -1;
    }
    ptr->F++;
    a = ptr->arr[ptr->F];

    return a;
}

int main()
{
    struct queue Q;
    Q.F = 0;
    Q.R = 0;
    Q.size = 50;
    Q.arr = (int *)malloc(Q.size * sizeof(int));
    //  enqueue(&Q,6);
    //  cout<<"the value queued is : "<<dequeue(&Q);
    // BFS implementation
    int visited[9] = {0,
                      0,
                      0,
                      0,
                      0,
                      0,
                      0,
                      0};
    int firstnode = 0;
    cout << firstnode;
    enqueue(&Q, firstnode);
    int a[9][9] = {
        {0, 1, 1, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0, 0}};
    do
    {
        int node = dequeue(&Q);

        for (int j = 0; j < 9; j++)
        {

            if (a[node][j] && visited[j] == 0)
            {
                enqueue(&Q, j);
                cout << j;
                visited[j] = 1;
            }
        }
    } while (!checkempty(&Q));

    return 0;
}
