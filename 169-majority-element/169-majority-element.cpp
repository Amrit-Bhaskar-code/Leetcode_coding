class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int res;
        for(int i=0;i<nums.size();i++)
        {
            if(map.find(nums[i])!=map.end())
            {
                map[nums[i]]++;
            }
            else
            {
                map[nums[i]]=1;
            }
        }
        for(auto& it: map)
        {
            if(it.second>nums.size()/2)
            {
                res = it.first;
            }
        }
        return res;
    }
};