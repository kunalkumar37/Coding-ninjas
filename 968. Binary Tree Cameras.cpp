class Solution
{
	int cam=0;
	public int minCameraCover(TreeNode root)
	{
		int ans=dfs(root);
		if(root==0)
		{
			return cam+1;
		}
		else
		{
			return cam;
		}

	}


	//2-- has camera
	//1-- covered with the camers
	//0-- no camera covered the node


	public int dfs(TreeNode node){
		if(node==NULL)
		{
			return 1;
		}

		int left=dfs(node->left);
		int right=dfs(node->right);

		//check if we nedd to add a camera
		if(left==0 or right==0)
		{
			cam++;
			return 2;
		}
		else if(left==2 or right==2)
		{
			return 1;

		}
		else

		{
			return 0;
		}

	}
};