class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini = nums[0];
        int res=INT_MIN;
        int current;
        for(int i=1;i<nums.size();i++)
        {
            current = mini;
            if(nums[i]<mini)
                mini = nums[i];
            if(nums[i]-mini<=0)
                continue;
            if(nums[i]-current > res)
                res = nums[i]-current;
             
        }
        return res==INT_MIN? -1:res;
    }
};