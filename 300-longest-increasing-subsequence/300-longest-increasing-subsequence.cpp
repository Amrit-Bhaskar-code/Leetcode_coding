class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[i]>nums[j])
                    res[i] = max(res[i], res[j]+1);
            }
        }
        int maxi = res[0];
        for(int i=1; i<nums.size(); i++)
        {
            if(res[i]>maxi)
                maxi = res[i];
        }
        return maxi;
    }
};