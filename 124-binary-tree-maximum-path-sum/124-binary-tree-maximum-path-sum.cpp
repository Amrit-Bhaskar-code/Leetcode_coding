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
    int util(TreeNode* root, int &res)
    {
        if(root==NULL)
            return 0;
        
        int l = util(root->left, res);
        int r = util(root->right, res);
        
        int single = max(max({l, r}) + root->val, root->val);
        
        int max_top = max( single, l+r+root->val);
        
        res = max(res, max_top);
        
        return single;
    }
    
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        
        util(root, res);
        return res;
    }
};