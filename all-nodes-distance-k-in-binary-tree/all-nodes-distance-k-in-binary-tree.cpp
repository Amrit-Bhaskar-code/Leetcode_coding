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
    void find_parent(TreeNode* root, unordered_map<TreeNode* , TreeNode*> &parent_map, TreeNode* prev)
    {
        if(root==NULL)
        {
            return;
        }
        parent_map[root] = prev;
        prev = root;
        find_parent(root->left, parent_map, prev);
        find_parent(root->right, parent_map, prev);
    }
    void bfs(TreeNode* target, int k, unordered_map<TreeNode*,TreeNode*> parent_map,  vector<int>& result)
    {
        queue<TreeNode* > q1;
        unordered_map<TreeNode*, int> visited;
        q1.push(target);
        
        while(k+1)
        {
           
            int size = q1.size();
            for(int i=0; i< size; i++)
            {
                TreeNode* popele = q1.front();
                visited[popele] = 1;
                q1.pop();
                cout<<"k val "<<k<<endl;
                if(k==0)
                {
                  result.push_back(popele->val);
                }
                
                   if(popele->left != NULL)
                    {
                        if(visited.find(popele->left) != visited.end()){
                        }
                        else
                        {
                           cout<<"left "<<popele->left->val<<endl;
                            q1.push(popele->left);
                        }
                    }
                    if(popele->right != NULL)
                    {
                        if(visited.find(popele->right) != visited.end()){
                        }
                        else
                        {
                           cout<<"right "<<popele->right->val<<endl;
                            q1.push(popele->right);
                        }                                          
                        
                    }
                    if(parent_map[popele] != NULL)
                    {
                        if(visited.find(parent_map[popele]) != visited.end()){
                        }
                        else
                        {
                           cout<<"parent "<<parent_map[popele]->val<<endl;
                            q1.push(parent_map[popele]);
                        } 
                        
                    }
                
            }
             k--;
            
        }
        
        
        
        
        
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        vector<int> result;
        unordered_map<TreeNode* , TreeNode*> parent_map;
        TreeNode* prev = NULL;
        find_parent(root, parent_map, prev);
        
        // cout<<parent_map[root->left]->val<<endl;
        // cout<<parent_map[root->right->left]->val<<endl;
        
        bfs(target, k, parent_map, result);
        return result;
    }
};