#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node*left;
    struct node*right;

};

struct node*newnode(int data)
{
    struct node*node=new struct node;
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

int heightoftree(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=heightoftree(root->left);
    int right=heightoftree(root->right);
    if(left>right)
    {
        return left+1;

    }
    else{
        return right+1;
    }
}

int main()
{
    struct node*root=newnode(1);
       root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    cout<<heightoftree(root);
    return 0;
}