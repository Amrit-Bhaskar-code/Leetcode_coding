class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = nums[0];
        int sum = 0;
        for(auto n: nums)
        {
            if(n<min)
            {
                min = n;
            }
            sum += n;
        }
        return sum - (min*nums.size());
    }
};