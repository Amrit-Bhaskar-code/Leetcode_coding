class Solution {
public:
    void dfs(vector<vector<int>>& m, int i, int j, char dir, vector<int>& res)
    {
        if(m[i][j]==-101 || i<0 || i>=m.size() || j<0 || j>=m[0].size())
            return;
        
        res.push_back(m[i][j]);
        m[i][j] = -101;
        
        if(dir=='r')
        {
            if(i>=0 && i<m.size() && j+1>=0 && j+1<m[0].size() && m[i][j+1]!=-101)
            {
                dfs(m, i, j+1, 'r', res);
            }
            else if(i+1>=0 && i+1<m.size() && j>=0 && j<m[0].size() && m[i+1][j]!=-101)
            {
                dfs(m, i+1, j, 'd', res);
            }
            else
            {
            }
        }
        if(dir=='d')
        {
            if(i+1>=0 && i+1<m.size() && j>=0 && j<m[0].size() && m[i+1][j]!=-101)
            {
                dfs(m, i+1, j, 'd', res);
            }
            else if(i>=0 && i<m.size() && j-1>=0 && j-1<m[0].size() && m[i][j-1]!=-101)
            {
                dfs(m, i, j-1, 'l', res);
            }
            else
            {
            }
        }
        if(dir=='l')
        {
            if(i>=0 && i<m.size() && j-1>=0 && j-1<m[0].size() && m[i][j-1]!=-101)
            {
                dfs(m, i, j-1, 'l', res);
            }
            else if(i-1>=0 && i-1<m.size() && j>=0 && j<m[0].size() && m[i-1][j]!=-101)
            {
                dfs(m, i-1, j, 'u', res);
            }
            else
            {
            }
        }
        if(dir=='u')
        {
            if(i-1>=0 && i-1<m.size() && j>=0 && j<m[0].size() && m[i-1][j]!=-101)
            {
                dfs(m, i-1, j, 'u', res);
            }
            else if(i>=0 && i<m.size() && j+1>=0 && j+1<m[0].size() && m[i][j+1]!=-101)
            {
                dfs(m, i, j+1, 'r', res);
            }
            else
            {
            }
        }
        
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        dfs(matrix, 0, 0, 'r', res);
        return res;
    }
};