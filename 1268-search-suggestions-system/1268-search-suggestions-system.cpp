class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        vector<string> prev = products;
        int count = 0;
        for(auto ch: searchWord)
        {
            vector<string> temp;
            vector<string> temp_req;
            for(auto str: prev)
            {
                if(ch == str[count])
                {
                    temp.push_back(str);
                }
            }
            sort(temp.begin(), temp.end());
            if(temp.size()>3)
            {
                for(int j=0;j<3;j++)
                {
                   temp_req.push_back(temp[j]);
                }
            }
            else
            {
                temp_req = temp;
            }
            res.push_back(temp_req);
            prev = temp;
            count++;
        }
        return res;
    }
};