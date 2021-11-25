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
    TreeNode* util(vector<int> nums, int l, int h)
    {
        if(l>h)
            return NULL;
        int m = l+ ((h-l)/2);
        TreeNode* n = new TreeNode(nums[m]);
        n->left = util(nums, l, m-1);
        n->right = util(nums, m+1, h);
        return n;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = NULL;
        int l = 0;
        int h = nums.size()-1; 
        return util(nums, l, h);
    }
};