#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *right;
    struct node *left;
};
struct node *createnode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
struct node* search(struct node* root,int key){
    if (root==NULL){
        return NULL;
    }
    if(key==root->data){
        return root;
    }
    else if(key<root->data)
    {
        return search(root->left,key);
    }
    else
    {
        return search(root->right,key);
    }
    
    
    
}
int main()
{
    // struct node* r,p1,p2;
    struct node *r = createnode(50);
    struct node *p1 = createnode(40);
    struct node *p2 = createnode(60);
    struct node *p3 = createnode(20);
    struct node *p4 = createnode(45);
    struct node *p5 = createnode(55);
    struct node *p6 = createnode(70);

    r->left = p1;
    r->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;
    
    struct node* p = search(r,4);
if(p!=NULL){
    cout<<"element found : "<<p->data<<endl;
}
else{
    cout<<"element not found"<<endl;
}
    return 0;
}