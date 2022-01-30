class Solution {
public:
    bool canJump(vector<int>& nums) {
            vector<int> dp(nums.size(), 100000);
            dp[0] = 0;
            int flag = 0;
            if(nums[0]==0)
                if(nums.size()==1)
                    return true;
                else
                    return false;
            for(int i=0; i<nums.size(); i++)
            {
                if(nums[i]==0)
                    continue;
                for(int j=1; i+j<nums.size() && j<=nums[i]; j++)
                {
                    if(dp[i+j]==100000)
                        dp[i+j] = min(dp[i] + 1, dp[i+j]);
                    if(i+j == nums.size()-1)
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag==1)
                    break;
            }
            // for(int i=0;i<nums.size();i++)
            // {
            //     cout<<dp[i]<<" ";
            // }
            return dp[nums.size()-1]==100000? false: true;
    }
};