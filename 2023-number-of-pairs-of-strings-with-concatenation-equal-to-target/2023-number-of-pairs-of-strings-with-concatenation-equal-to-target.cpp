class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map <string, int> freq;
        int res=0;
        for(string s:nums)
        {
            if(s.length()<target.length())
            {
                freq[s]++;
            }
        }
        
        for(auto [k,v] : freq)
        {
            if(target.find(k)==0)
            {
                if( k+k == target)
                {
                    res += v*(v-1); 
                }
                else
                {
                    res += v * freq[target.substr(k.length())];
                }
            }
        }
        return res;
    }
};