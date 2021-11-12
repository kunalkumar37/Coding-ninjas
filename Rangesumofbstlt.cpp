#include<bits/stdc++.h>
using namespace std;

// a binary search tree creation
class Node{
    public:
        int val;
        Node*left,*right;

};

//function to create a new bst node
Node* newnode(int item)
{
    Node*temp=new Node();
    temp->val=item;
    temp->left=temp->right=NULL;

    return temp;
}

int sum=0;

int rangesumofbst(Node* root,int low,int high)
{
    //base case
    if(root==NULL)
    {
        return 0;
    }

    //stores the nodes while performing level order traversal
    queue<Node*>q;
    q.push(root);
    while(q.empty()==false)
    {
        Node* curr=q.front();
        q.pop();


        if(curr->val>=low and curr->val<=high)
        {
            sum=sum=curr->val;

        }
        if(curr->left!=NULL and curr->val>low)
        {
            q.push(curr->left);
        }
        if(curr->right!=NULL and curr->val<high)
        {
            q.push(curr->right);

        }
    }
    return sum;
}

//function to insert a new node into the binary search tree
Node* insert(Node* node,int data)
{
    if(node==NULL)
    {
        return newnode(data);

    }
    if(data<=node->val)
    {
        node->left=insert(node->left,data);
    }
    else{
        node->right=insert(node->right,data);
    }
    return node;

}

int main()
{
    Node* root=NULL;
    root=insert(root,10);
    insert(root,5);
    insert(root,15);
    insert(root,3);
    insert(root,7);
    insert(root,18);

    int l=7,r=15;
    cout<<rangesumofbst(root,l,r);
    return 0;

}