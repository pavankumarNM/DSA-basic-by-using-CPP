#include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int height;
    struct node *left;
    struct node *right;
    int key;
};
int getheight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}
struct node *createnode(int key)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->left = NULL;
    node->right = NULL;
    node->key = key;
    node->height = 1;
    return node;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getbal(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getheight(n->left)-getheight(n->right);
}
struct node *leftrotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
    y->left = x;
    x->right = T2;
    y->height=1+max(getheight(y->right),getheight(y->left));
    x->height=1+max(getheight(x->right),getheight(x->left));
    return y;
}
struct node *rightrotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height=1+max(getheight(y->right),getheight(y->left));
    x->height=1+max(getheight(x->right),getheight(x->left));
    return x;
}
struct node *insertnode(struct node *root, int key)
{
    if (root == NULL)
    {
        return (createnode(key));
    }
    if (key < root->key)
    {
        return root->left = insertnode(root->left, key);
    }
    else if (key > root->key)
    {
        return root->right = insertnode(root->right, key);
        return root;
    }
    int bf = getbal(root);
    root->height=1+max(getheight(root->left),getheight(root->right));
    // R R
    if (bf < -1 && key > root->right->key)
    {
      return  root = leftrotate(root);
    }

    // L L
    if (bf > 1 && key < root->left->key)
    {
      return  root = rightrotate(root);
    }

    // R L
    if (bf < -1 && key > root->right->key)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    // L R 
    if (bf > 1 && key > root->left->key)
    {
        root->left = rightrotate(root->left);
       return  rightrotate(root);
    }

    return root;
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->key << " " << endl;
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    struct node *root=NULL;
    root = insertnode(root, 1);
    root = insertnode(root, 2);
    root = insertnode(root, 6);
    root = insertnode(root, 3);
    root = insertnode(root, 4);
    preorder(root);
    return 0;
}
// not able to solve this fucking shitty things soo called this off