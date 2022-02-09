class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l=0 , r=0;
        int n = nums.size();
        int max_prod = nums[0];
        for(int i=0; i<n; i++)
        {
            l = (l? l : 1) * nums[i];
            r = (r? r : 1) * nums[n-i-1];
            max_prod = max(max_prod, max(l, r));
        }
        return max_prod;
    }
};