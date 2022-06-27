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
struct node *inorderpre(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *deleteBST(struct node *root, int val)
{
    struct node *ipre = NULL;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->right == NULL && root->left == NULL)
    {
        free(root);
        return NULL;
    }
    if (root->data < val)
    {
        deleteBST(root->left, val);
    }
    else if (root->data > val)
    {
        deleteBST(root->right, val);
    }
    else
    {
        ipre = inorderpre(root);
        root->data = ipre->data;
        root->left = deleteBST(root->left, ipre->data);
    }
    return root;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {

        inorder(root->left);
        cout << root->data << " "<<endl;
        inorder(root->right);
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
    inorder(r);
    deleteBST(r, 45);
    cout<<endl;
    inorder(r);
    cout << r->left->right->data;
    return 0;
}

//solved this one but not understand clearly will watch another video in the youtube okkkkkk