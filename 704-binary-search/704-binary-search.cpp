class Solution {
public:
    int binary_search(vector<int>& nums, int target, int l, int h)
    {
        if(l>h)
            return -1;
        int m  = l + (h-l)/2;
        if(nums[m]==target)
        {
            return m;
        }
        if(nums[m]>target)
        {
            return binary_search(nums, target, l, m-1);
        }
        else
        {
            return binary_search(nums, target, m+1, h);
        }
        return -1;
    }
    
    
    int search(vector<int>& nums, int target) {
        int l=0, h = nums.size()-1; 
        int res = binary_search(nums, target, l, h);
        return res;
    }
};