#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
void Displaynode(struct Node *ptr)
{

    while (ptr != NULL)
    {

        cout << "element : " << ptr->data;
        ptr = ptr->next;
        cout << endl;
    }
}
struct Node *insertionBegin(struct Node *head, int data)
{
    struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));
    ptr1->next = head;
    ptr1->data = data;
    return ptr1;
}
struct Node *insertionEnd(struct Node *head, int data)
{
   cout<<"after end insertion "<<endl;
    struct Node *ptr3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr3->data = data;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next=ptr3;
    ptr3->next = NULL;
    return head;
}
struct Node *insertionIndex(struct Node *head, int data, int index)
{
    struct Node *ptr2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 1;
    ptr2->data = data;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr2->next = p->next;
    p->next = ptr2;
    return head;
}

int main()
{ // initializing the pointer to each node
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // allocating the pointer to each node
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // linking of head and second node
    head->data = 1;
    head->next = second;
    // linking of second and third node
    second->data = 2;
    second->next = third;
    // linking of third and fourth node
    third->data = 3;
    third->next = fourth;
    // declaring the fourth node to NULL
    fourth->data = 4;
    fourth->next = NULL;
    Displaynode(head);
    cout << "after insertion at index  " << endl;
    // Displaynode(insertionBegin(head,0));
    head = insertionIndex(head, 13, 3);
    Displaynode(head);
    head = insertionEnd(head, 100);
    Displaynode(head);
    return 0;
}