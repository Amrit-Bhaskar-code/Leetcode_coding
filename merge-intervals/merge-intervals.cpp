class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int res_count = 0;
        
        
        for(int i=0; i<intervals.size();i++)
        {
            if(res.size()==0)
            {
                res.push_back(intervals[i]);
                res_count++;
            }
            else
            {
                if(res[res_count-1][1]>=intervals[i][0])
                {
                    if(intervals[i][1]>res[res_count-1][1])
                        res[res_count-1][1] = intervals[i][1];
                }
                else
                {
                    res.push_back(intervals[i]);
                    res_count++;
                }
            }
        }
        return res;
    }
};