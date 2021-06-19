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
    void inorderk(TreeNode* root, int* k, int& ans)
    {
        if(root!=NULL && (*k)>0)
        {
            inorderk(root->left, k, ans);
            
            if(*k==0)
                return;
            ans = root->val;
            cout<<ans<<" "<<*k<<endl;
            
            (*k)--;
            
            inorderk(root->right, k, ans);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inorderk(root,&k, ans);
        return ans;
    }
};