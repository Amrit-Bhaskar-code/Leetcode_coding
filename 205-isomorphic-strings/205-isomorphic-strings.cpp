class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())
        {
            return false;
        }
        vector<int> a(150, 0);
        unordered_map<char, char> map;
        for(int i=0;i<s.length();i++)
        {
            if(map.find(s[i])!=map.end())
            {
                if(t[i]!=map[s[i]])
                {
                    return false;
                }
            }
            else
            {
                map[s[i]] = t[i];
                if(a[t[i]]!=0)
                {
                    return false;
                }
                a[t[i]] = 1;
            }
        }
        return true;
    }
};