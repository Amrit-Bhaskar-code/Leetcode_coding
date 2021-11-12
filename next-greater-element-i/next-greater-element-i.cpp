class Solution {
public:
    int find(int m, stack<int> s)
    {
        int res = -1;
        while(s.top() != m)
        {
            if(s.top() > m)
            {
                res = s.top();
            }
            s.pop();
        }
        return res;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        for(int i=0;i<nums2.size();i++)
        {
            s.push(nums2[i]);
        }
        vector<int> result;
        for(int i=0;i<nums1.size();i++)
        {
            result.push_back(find(nums1[i], s));
        }
        return result;
    }
};