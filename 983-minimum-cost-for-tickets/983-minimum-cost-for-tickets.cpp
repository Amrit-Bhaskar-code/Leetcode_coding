class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int max_days = days[days.size()-1];
        cout<<max_days;
        vector<int> dp(max_days+1, 0);      
        unordered_set<int> temp(days.begin(), days.end());
        for(int i=1; i<=max_days; i++)
        {
            if(temp.find(i) != temp.end())
            {
                dp[i] = min({dp[max(0,i-1)] + costs[0], dp[max(0,i-7)] +costs[1], dp[max(0,i-30)] +costs[2]});
            }
            else
            {
                dp[i] = dp[i-1];
            }
        }
        return dp[max_days];
    }
};