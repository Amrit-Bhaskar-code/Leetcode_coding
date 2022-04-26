class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_till_now = prices[0];
        int profit = 0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]-min_till_now>profit)
            {
                profit = prices[i]-min_till_now;
            }
            if(prices[i]<min_till_now)
            {
                min_till_now = prices[i];
            }
        }
        
        return profit;
    }
};