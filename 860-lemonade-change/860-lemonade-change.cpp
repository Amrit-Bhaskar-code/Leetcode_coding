class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> change(2,0);
        for(int i=0; i<bills.size(); i++)
        {
            if(bills[i]==5)
            {
                // cout<<bills[i]<<endl;
                change[0]++;
            }
            if(bills[i]==10)
            {
                // cout<<bills[i]<<endl;
                if(change[0]==0)
                {
                    return false;
                }
                change[0]--;
                change[1]++;
            }
            if(bills[i]==20)
            {
                // cout<<bills[i]<<endl;
                if(change[0]==0)
                    return false;
                else if(change[1]>0 and change[0]>0)
                {
                   change[0]--;
                   change[1]--; 
                }
                
                else if(change[1]==0 and change[0]<=2)
                {
                    return false;
                }
                else if(change[1]==0 and change[0]>2)
                {
                    change[0]-=3;
                }
            }
        }
        return true;
    }
};