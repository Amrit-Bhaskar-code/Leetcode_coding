class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;
        string t="";
        for(auto s:strs)
        {
            t = s;
            sort(s.begin(), s.end());
            map[s].push_back(t);
        }
        for(auto it:map)
        {
            res.push_back(it.second);
        }
        return res;
    }
};