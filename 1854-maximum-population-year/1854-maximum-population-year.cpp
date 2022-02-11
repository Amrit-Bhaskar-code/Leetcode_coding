class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> map(101, 0);
        for(auto v : logs)
        {
            map[v[0]-1950]++;
            map[v[1]-1950]--;
        }
        int maxim = 0;
        for(int i=1;i<101;i++)
        {
            map[i] += map[i-1];
            if(map[maxim] < map[i])
                maxim = i;
        }
        return maxim + 1950;
    }
};