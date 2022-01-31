class Solution {
public:
    int rob(vector<int>& nums) {
        int max_sum_till_here = nums[0];
        int max_sum_exc_here = 0;
        for(int i=1;i<nums.size();i++)
        {
            int temp = max_sum_exc_here;
            max_sum_exc_here = max_sum_till_here;
            max_sum_till_here = max(temp + nums[i], max_sum_till_here);            
        }
        return max_sum_till_here;
    }
};