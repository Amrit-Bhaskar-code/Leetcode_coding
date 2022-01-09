class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<vector<int>> unq(nums.size());
        vector<int> res;
        for(int i:nums)
        {
            freq[i]++;
        }
        
        sort(begin(nums), end(nums), [&](int a, int b) {
            return freq[a] == freq[b] ? a < b : freq[a] > freq[b];
        });
        
        // for(int i=0;i<nums.size();i++)
        // {
        //     cout<<nums[i]<<" ";
        // }
        
        int prev=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(prev == nums[i])
                continue;
            res.push_back(nums[i]);
            if(res.size()==k)
                break;
            prev = nums[i];
        }
        
        return res;
    }
};