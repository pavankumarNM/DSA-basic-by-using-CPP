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
void preorder(struct node *root)
{if(root!=NULL){
    cout<<root->data<<" "<<endl;
    preorder(root->left);
    preorder(root->right);}
}
int main()
{
    // struct node* r,p1,p2;
    struct node *r = createnode(1);
    struct node *p1 = createnode(2);
    struct node *p2 = createnode(3);
    struct node *p3 = createnode(4);
    struct node *p4 = createnode(5);
    
    r->left = p1;
    r->right = p2;
    p1->left = p3;
    p1->right = p4;
    preorder(r);
    return 0;
}