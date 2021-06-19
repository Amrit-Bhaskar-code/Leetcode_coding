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
    void util(TreeNode* root, int max_val, int& temp)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->val >= max_val)
        {
            max_val = root->val;
            temp++;
        }
        util(root->left, max_val, temp);
        util(root->right, max_val, temp);
            
    }
    
    int goodNodes(TreeNode* root) {
        int max_val = root->val;
        int ans = 1;
        int temp_l = 0;
        int temp_r = 0;
        util(root->left, max_val, temp_l);
        util(root->right, max_val, temp_r);
        
        return ans + temp_l + temp_r;
    }
};