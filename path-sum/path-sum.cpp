/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void util(TreeNode* root, int targetSum, bool &res, int s)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            // cout<<s<<endl;
            if(s+root->val==targetSum)
            {
                // cout<<"hello"<<endl;
                res = true;
            }
            else
            {
                return;
            }
        }
        s += root->val;
        util(root->left, targetSum, res, s);
        util(root->right, targetSum, res, s);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool res = false;
        int s = 0;
        util(root, targetSum, res, s);
        return res;
    }
};