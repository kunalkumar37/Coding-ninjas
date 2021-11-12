class Solution{
    TreeNode* newroot,*curr;
    public:
        TreeNode* increasingBST(TreeNode* root)
        {
            if(root==NULL)
            {
                return NULL;
            }
            increasingBST(root->left);
            if(newroot==NULL)
            {
                newroot=new TreeNode(root->val);
                curr=newroot;
            }
            else{
                curr->right=new TreeNode(root->val);
                curr=curr->right;

            }
            increasingBST(root->right);
            return newroot;
        }
};