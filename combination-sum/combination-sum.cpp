class Solution {
public:
    void util(vector<int>& candidates, vector<vector<int>>& res, vector<int> combination,
             int target, int begin)
    {
        if(target==0)
        {
            res.push_back(combination);
            return;
        }
        for(int i=begin; i<candidates.size() && candidates[i]<=target; i++)
        {
            combination.push_back(candidates[i]);
            util(candidates, res, combination, target-candidates[i], i);
            combination.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        util(candidates, res, combination, target, 0);
        return res;
    }
};