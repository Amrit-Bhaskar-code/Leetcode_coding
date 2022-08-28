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
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(target < matrix[0][0]) return false;

        
        for(int i = 0; i < matrix.size(); i++)
        {
            if(matrix[i][0] <= target && matrix[i][matrix[i].size()-1] >= target)
            {
                int l = 0, h = matrix[i].size()-1;
                return binary_search(matrix[i], target, l, h) != -1 ? true: false;
            }
        }
        return false;
    }
};