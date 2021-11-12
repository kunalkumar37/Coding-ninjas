#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left,*right;

};

Node* newnode(int item)
{
    Node* temp=new Node();
    temp->val=item;
    temp->left=temp->right=NULL;
    return temp;
}

Node* mergetwobinarytree(Node* t1,Node* t2)
{
    if(t1 and t2)
    {
        t1->val+=t2->val;
        t1->left=mergetwobinarytree(t1->left,t2->left);
        t1->right=mergetwobinarytree(t1->right ,t2->right);

    }
    else{
        return t1?t1:t2;
    }
    return t1;
}

Node* insert(Node*root,int data)
{
    if(root==NULL)
    {
        return newnode(data);
    }
    else{
        root->left=data;
        
    }
}





int main()
{

}