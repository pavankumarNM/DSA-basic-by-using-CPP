#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
void Displaynode(struct Node *head)
{
    struct Node*  ptr=head;
    do
    {

        cout << "element : " << ptr->data;
        ptr = ptr->next;
        cout << endl;
    }while (ptr!=head);
}
struct Node* Inserthead(struct Node* head,int data){
struct Node* ptr = (struct Node *)malloc(sizeof(struct Node));
ptr->data=data;
cout<<"after head insertion"<<endl;
struct Node* p=head;
do
{
    p=p->next;
} while(p->next!=head);
p->next=ptr;
ptr->next=head;
head=ptr;
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
    fourth->next = head;
    Displaynode(head);
    head=Inserthead(head,0);
      Displaynode(head);
       return 0;
}