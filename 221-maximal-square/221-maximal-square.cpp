class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res=0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                dp[i][j] = matrix[i][j] - '0';
            }
        }
        for(int i=1; i<matrix.size(); i++)
        {
            for(int j=1; j<matrix[0].size(); j++)
            {
                if(dp[i][j]==1)
                {
                    dp[i][j] = min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}) + 1;
                }
            }
        }
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(i==0 || j==0)
                    dp[i][j] = matrix[i][j]-'0';
                // cout<<dp[i][j]<<" ";
                if(dp[i][j]>res)
                    res = dp[i][j];
            }
            // cout<<endl;
        }
        return res*res;
    }
};