class Solution {
public:
    void dfs(vector<vector<int>>& M, vector<int>& visited, int i) {
        for (int j = 0; j < M.size(); j++) {
            if (M[i][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                dfs(M, visited, j);
            }
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int ans = 0;
        vector<int> visited(isConnected.size()+1,0);
        for(int i=0;i<isConnected.size();i++)
        {
            if(visited[i]==0)
            {
                dfs(isConnected, visited, i);
                ans++;
            }
        }
        return ans;
    }
};