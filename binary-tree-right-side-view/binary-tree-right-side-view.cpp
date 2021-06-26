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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> result;
        queue<TreeNode* > q1;
       
        if(root==NULL)
        {
            return result;
        }
        q1.push(root);
       
       
       
        while(!q1.empty())
        {
            int size = q1.size();
           
            for(int i=0; i< size; i++)
            {
                TreeNode* popele = q1.front();
                q1.pop();
               
                if(i==size-1)
                    result.push_back(popele->val);
               
                if(popele->left != NULL)
                {
                   
                    q1.push(popele->left);
                }
               
                if(popele->right != NULL)
                {
               
                    q1.push(popele->right);
                }
               
            }
           
           
        }
     return result;  
        
        
    }
};