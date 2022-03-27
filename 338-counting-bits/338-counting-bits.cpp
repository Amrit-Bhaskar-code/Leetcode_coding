class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0; i<=n; i++)
        {
            int temp = i;
            int res_int = 0;
            while(temp!=0)
            {
                res_int += temp & 1;
                temp = temp>>1;
            }
            res.push_back(res_int);
        }
        return res;
    }
};