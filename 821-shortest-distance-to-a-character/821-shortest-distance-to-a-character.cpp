class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
//         int l = 0, r=s.length()-1;
//         int l_c = 0, r_c = 0;
        vector<int> res(s.length(), 0);
//         while(s[l]!=c)
//         {
//             l++;
//             l_c++;
//         }
//         while(s[r]!=c)
//         {
//             r--;
//             r_c++;
//         }
//         res[0] = l_c, res[s.length()-1] = r_c;
        
        
//         l = 0, r=s.length()-1;
        
        int temp = INT_MAX;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==c)
            {
                temp = i;
                res[i] = 0;
            }
            else
            {
                res[i] = abs(temp-i);
            }
        }
        temp = INT_MAX;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]==c)
            {
                temp = i;
                res[i] = 0;
            }
            else
            {
                res[i] = min(abs(temp-i), res[i]);
            }
        }
        return res;
    }
};