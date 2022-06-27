#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
void Display(struct Node *ptr)
{
    cout << "forward transversal " << endl;
    do
    {
        cout << "element : " << ptr->data << endl;
        ;
        ptr = ptr->next;

    } while (ptr->next != NULL);
    cout << "element : " << ptr->data << endl;

    cout << "reversal transversal " << endl;

    do
    {
        cout << "element : " << ptr->data << endl;
        ;
        ptr = ptr->prev;

    } while (ptr->prev != NULL);
    cout << "element : " << ptr->data;
}
int main()
{
    struct Node *N1;                                               // creating Nodes
    struct Node *N2;
    struct Node *N3;
    struct Node *N4;

    N1 = (struct Node *)malloc(sizeof(struct Node));
    N2 = (struct Node *)malloc(sizeof(struct Node));
    N3 = (struct Node *)malloc(sizeof(struct Node));
    N4 = (struct Node *)malloc(sizeof(struct Node));

    N1->data = 1;                                             // initializing values for the Nodes
    N1->prev = NULL;
    N1->next = N2;

    N2->data = 2;
    N2->prev = N1;
    N2->next = N3;

    N3->data = 3;
    N3->prev = N2;
    N3->next = N4;

    N4->data = 4;
    N4->prev = N3;
    N4->next = NULL;

    Display(N1);
     Display(N2);
     Display(N3);
     Display(N4);
    

    return 0;
}
