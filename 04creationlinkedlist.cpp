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
struct Node* Begin(struct Node* head,int data){
    cout<<"after begin"<<endl;
    struct Node* ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    head=ptr;
    return head;
}
struct Node* End(struct Node* head,int data){
    cout<<"after End"<<endl;
    struct Node* ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node* p=head;
      ptr->data=data;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
struct Node* Afternode(struct Node* head,struct Node* previousnode,int data){
    cout<<"after Afternode"<<endl;
    struct Node* ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=previousnode->next;
    previousnode->next=ptr;
    return head;
}
struct Node* Index(struct Node* head,int data,int index){
    cout<<"after indexing "<<endl;
    struct Node* ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node* p=head;
    ptr->data=data;
    int i=0;
    while (i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
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
    head=Begin(head,0);
    Displaynode(head);
    head=Index(head,22,2);
    Displaynode(head);
    head=End(head,100000000);
    Displaynode(head);
    head=Afternode(head,third,5);
    Displaynode(head);
    return 0;
}
