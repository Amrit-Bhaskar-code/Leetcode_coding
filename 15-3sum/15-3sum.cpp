class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if(nums.size()<3)
            return res;
        for(int i=0; i<nums.size()-2; i++)
        {
            if(i==0 || (i>0 && nums[i]!=nums[i-1]))
            {
                int l = i+1;
                int h = nums.size()-1;
                while(l<h)
                {
                    if(nums[i] + nums[l] + nums[h]==0)
                    {
                        res.push_back({nums[i], nums[l], nums[h]});
                        while(l<h && nums[l]==nums[l+1])
                        {
                          l++;
                        }
                        while(h>l && nums[h]==nums[h-1])
                        {
                          h--;
                        }
                        l++;
                        h--;
                    }
                    else if(nums[i] + nums[l] + nums[h] > 0)
                    {
                        h--;
                    }
                    else
                    {
                        l++;
                    }
                }
            }
        }
        return res;
    }
};