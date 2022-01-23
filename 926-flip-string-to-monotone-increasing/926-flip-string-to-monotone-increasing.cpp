class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int counter_one = 0;
        int counter_flip = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
            {
                counter_one++;
            }
            else
            {
                counter_flip++;
            }
            counter_flip = min(counter_flip, counter_one);
        }
        return counter_flip;
    }
};