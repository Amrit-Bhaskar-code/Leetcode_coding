class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ans;
        vector<pair<string,string>> letter_logs;
        vector<string> digit_logs;
        int i;
        for(string s: logs)
        {
            i=0;
            while(s[i]!=' ') i++;
            if(isalpha(s[i+1]))
            {
                 letter_logs.push_back(make_pair(s.substr(0,i), s.substr(i+1)));
            }
            else
            {
                digit_logs.push_back(s);
            }
        }
        sort(letter_logs.begin(), letter_logs.end(), [&](auto& a, auto& b) {
            return a.second == b.second ? a.first < b.first : a.second < b.second;
        });
        for(auto i: letter_logs)
        {
            ans.push_back(i.first + " " + i.second);
        }
        for(auto i: digit_logs)
        {
            ans.push_back(i);
        }
        return ans;
    }
};