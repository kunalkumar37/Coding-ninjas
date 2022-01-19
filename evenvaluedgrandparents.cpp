#include<bits/stdc++.h>
using namespace std;


struct Treenode
{
	int data;
	Treenode *left,*right;
	Treenode(int x)
	{
		data=x;
		left=right=NULL;

	}
};



void getsum(Treenode*curr,Treenode*p,Treenode*gp,int sum)
{
	if(curr==NULL)
		{
			return;
		}
		if(gp!=NULL and gp->data%2==0)
		{
			sum=sum+curr->data;
		}

		getsum(curr->left,curr,p,sum);
		getsum(curr->right,curr,p.sum);
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    

    Treenode *root=new Treenode(22);
    root->left=new Treenode(3);
    root->right = new TreeNode(8);
 
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(8);
 
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(9);
    root->right->right->right = new TreeNode(2);
 int sum=0;
 getsum(root,NULL,NULL,sum);
 cout<<sum<<endl;
 return 0;
}