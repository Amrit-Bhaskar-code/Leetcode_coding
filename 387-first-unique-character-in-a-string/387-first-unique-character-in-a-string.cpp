class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        char c='_';
        int res=-1;
        for(int i=0;i<s.length();i++)
        {
            if(m.find(s[i])!=m.end())
            {
                m[s[i]]+=1;
            }
            else
            {
                m[s[i]] = 1;
            }
        }
        
        unordered_map<char, int> :: const_iterator it;
        for( it=m.begin(); it!=m.end(); it++)
        {
            if(it->second == 1)
            {
                c = it->first;
            }
        }
        //cout<<c<<endl;
        if(c=='_')
            return res;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == c)
                res = i;
        }
        return res;
    }
};