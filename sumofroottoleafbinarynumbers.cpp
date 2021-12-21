#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node*left;
    struct node* right;

};

struct node*newnode(int data)
{
   struct node*node=new struct node;
   node->data=data;
   node->left=NULL;
   node->right=NULL;
   return node;
}
int sol=0;
int sumofbinarytree(node*root,int num=0)
{
    
    if(root==NULL)
    {
        return 0;
    }

    num=num*2;
    num=num+root->data;
    if(!root->left and !root->right)
    {
        sol=sol+num;
    }
    sumofbinarytree(root->left,num);
    sumofbinarytree(root->right,num);
    return sol;
}
int main()
{
    struct node*root= newnode(1);
    root->left=newnode(0);
    root->left->left=newnode(1);
    root->left->right=newnode(0);
    root->right=newnode(0);
    root->right->left=newnode(1);
    root->right->right=newnode(0);
    int num=0;
    cout<<sumofbinarytree(root,num);
    return 0;
}