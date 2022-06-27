#include<iostream>
using namespace std;
struct Node
{
    int data;struct Node* next;

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
struct Node* Begin(struct Node* head){
    cout<<"After begin deletion "<<endl;
    struct Node* ptr=head;
   head=head->next;
   free(ptr);
   return head;
}
struct Node* Index(struct Node* head,int index){
    cout<<"After index deletion "<<endl;
    struct Node* p=head;
    struct Node* q=head->next;
    int i=0;
    if(i==index){
        free(p);
        return q;
    }
      for(int i=0;i<index-1;i++){

          p=p->next;
          q=q->next;
      }
     p->next=q->next;
     free(q);
     return head;
     
   
}
struct Node* Key(struct Node* head,int key){
    cout<<"After key deletion "<<endl;
    struct Node* ptr;
    struct Node* q=head;
    ptr=q->next;
  if (q->data==key)
    {
        head=q->next;
        free(q);
        return head;
    } 
    while(ptr->data!=key){
        ptr=ptr->next;
        q=q->next;
    }
    q->next=ptr->next;
    free(ptr);
    return head;
}
struct Node* End(struct Node* head){
    cout<<"After end deletion "<<endl;
    struct Node* p;
      struct Node* q=head;
     p=q->next;
    
    while(p->next!=NULL){
        q=q->next;
        p=p->next;
        
    }
    q->next=NULL;
    free(p);
    
   return head;
}


int main(){
    struct Node* head=(struct Node*)malloc(sizeof(struct Node*));
    struct Node* second=(struct Node*)malloc(sizeof(struct Node*));
    struct Node* third=(struct Node*)malloc(sizeof(struct Node*));
    struct Node* four=(struct Node*)malloc(sizeof(struct Node*));
    struct Node* five=(struct Node*)malloc(sizeof(struct Node*));
    struct Node* six=(struct Node*)malloc(sizeof(struct Node*));
    struct Node* seven=(struct Node*)malloc(sizeof(struct Node*));
    struct Node* eight=(struct Node*)malloc(sizeof(struct Node*));
    struct Node* nine=(struct Node*)malloc(sizeof(struct Node*));
    head->data=0;                           
    head->next=second;
    second->data=1;
    second->next=third;
    third->data=2;
    third->next=four;
    four->data=3;
    four->next=five;
    five->data=4;
    five->next=six;
    six->data=5;
    six->next=seven;
    seven->data=6;
    seven->next=eight;
    eight->data=7;
    eight->next=nine;
    nine->data=8;
    nine->next=NULL;
    Displaynode(head);     
    head=Begin(head);          //deleting the  node at begining
    Displaynode(head);
    head=Index(head,2);        //deleting the  node at index
    Displaynode(head);
    head=End(head);             //deleting the node at end
    Displaynode(head);
    head=Key(head,4);           //deleting the node at key value
    Displaynode(head);
    return 0;
    
}