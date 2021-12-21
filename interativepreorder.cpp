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

void iterativeway(node*root)
{
    if(root==NULL)
    {
        return;
    }
    stack<node*>stc;
    stc.push(root);
    while(!stc.empty())
    {
        struct node*node=stc.top();
        cout<<node->data;
        stc.pop();
        if(node->right)
        {
            stc.push(node->right);

        }
        if(node->left)
        {
            stc.push(node->left);
        }
    }
}


int main()
{
    struct node*root=newnode(10);
    root->left=newnode(8);
    root->right=newnode(2);
    root->left->left=newnode(3);
    root->left->right=newnode(5);
    root->right->left=newnode(2);

    iterativeway(root);
    return 0;
}
