class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int h=numbers.size()-1;
        vector<int> res;
        while(l<h)
        {
            if(numbers[l]+numbers[h]==target)
            {
                res.push_back(l+1);
                res.push_back(h+1);
                break;
            }
            while(l<h && numbers[l]+numbers[h]>target)
            {
                h--;
            }
            while(l<h && numbers[l]+numbers[h]<target)
            {
                l++;
            }
        }
        return res;
    }
};