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
    bool util(TreeNode* m, TreeNode* n)
    {
        if(m==NULL && n==NULL)
            return true;
        if(m==NULL || n==NULL)
            return false;
        return (m->val==n->val && util(m->left, n->right) && util(m->right, n->left));
    }
    
    bool isSymmetric(TreeNode* root) {
        return util(root, root);
    }
};