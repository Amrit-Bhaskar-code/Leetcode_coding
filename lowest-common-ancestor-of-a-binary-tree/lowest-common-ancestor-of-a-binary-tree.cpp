/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int util(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans)
    {
        if(root==NULL)
        {
            return 0;
        }
       int l = util(root->left, p, q, ans)>0 ? 1:0;
       int r = util(root->right, p, q, ans)>0? 1:0;
        
        int m=0;
        if(root==p || root==q)
        {
            m=1;
        }
        if((l+m+r)>=2)
        {
            ans = root;
        }
        return (l+m+r);
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        util(root, p, q, ans);
        return ans;
    }
};