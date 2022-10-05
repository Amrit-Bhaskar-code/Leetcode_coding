class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
      unordered_map<char, int> mapi;
        int j=0;
        int res = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(mapi.find(s[i])!=mapi.end())
            {
                j = max(j, mapi[s[i]]+1);
            }
            // cout<<s[i]<<" "<<j<<endl;
            mapi[s[i]] = i;
            res = max(res, i-j+1);
        }
        return res;
    }
};