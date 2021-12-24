#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node*newnode(int data)
{
    struct node*node=new struct node();
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;

}

bool isunivaltree(node* root)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->left!=NULL and root->left->data!=root->data)
    {
        return false;
    }
    if(root->right!=NULL and root->right->data!=root->data)
    {
        return false;

    }
    return isunivaltree(root->left) and isunivaltree(root->right);
}

int main()
{
    struct node*root=newnode(10);
    root->left=newnode(8);
    root->right=newnode(2);
    root->left->left=newnode(3);
    root->left->right=newnode(5);
    root->right->left=newnode(2);
    cout<<isunivaltree(root);
    return 0;
}