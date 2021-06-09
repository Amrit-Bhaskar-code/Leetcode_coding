class Solution {
public:
    void util(int n, vector<string>& res, string combination, int sum)
    {
        if(sum<0)
            return;
        if(combination.length()>(2*n))
        {
            return;
        }
        if(combination.length()==(2*n) && sum==0)
        {
            res.push_back(combination);
            return;
        }
        if(combination.length()==(2*n) && sum!=0)
        {
            return;
        }
        util(n, res, combination+")", sum-1);
        util(n, res, combination+"(", sum+1);
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string combination = "(";
        int sum=1;
        util(n, res, combination, sum);
        return res;
    }
};