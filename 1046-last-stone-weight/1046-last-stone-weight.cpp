class Solution {
public:
    void place_temp(vector<int>& stones, int temp, int n)
    {
        int i=0;
       for(i=0; i<n;i++)
       {
           if(stones[i]>temp)
               break;
       }
        if(i==0)
        {
           stones.insert(stones.begin(), temp);
            return;
        }
        stones.insert(stones.begin() + i, temp);
    }
    void print_array(vector<int>& stones)
    {
        int n = stones.size();
        for(int i=0;i<n;i++)
        {
            cout<<stones[i]<<" ";
        }
        cout<<endl;
    }
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        sort(stones.begin(), stones.end());
        while(n>1)
        {
            if(stones[n-2]==stones[n-1])
            {
                n = n-2;
            }
            else
            {
                int temp = stones[n-1] - stones[n-2];
                place_temp(stones, temp, n-2);
                n = n-1;
            }
            // break;
            // print_array(stones);
        }
        if(n==0)
            return 0;
        return stones[0];
    }
};