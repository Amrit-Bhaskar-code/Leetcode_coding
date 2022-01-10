class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // int res=nums[nums.size()-1];
        int count = 1;
        int max = nums[nums.size()-1];
        int prev= nums[nums.size()-1];
        for(int i=nums.size()-2; i>=0; i--)
        {
            if(nums[i]>max)
            {
                max = nums[i];
            }
            if( prev == nums[i])
                continue;
            else
            {
                prev = nums[i];
                count++;
                if(count==3)
                    break;
            }
        }
        if(count<3)
            return max;
        return prev;
    }
};