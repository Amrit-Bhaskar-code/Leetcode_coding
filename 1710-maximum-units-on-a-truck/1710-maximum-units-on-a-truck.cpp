class Solution {
public:
    static bool sortfunc(const vector<int>& p1, const vector<int>& p2)
    {
        return p1[1]>p2[1];
    }
    
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), sortfunc);
        int sum = truckSize;  
        int res = 0;
        // for(int i=0;i<boxTypes.size();i++)
        // {
        //     for(int j=0;j<2;j++)
        //     {
        //         cout<<boxTypes[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        
        for(int i=0; i<boxTypes.size(); i++)
        {
            int temp = boxTypes[i][0] * boxTypes[i][1];
            if(sum-boxTypes[i][0]>0)
            {
                sum = sum-boxTypes[i][0];
                res += temp;
            }
            else
            {
                while(sum--)
                {
                    res += boxTypes[i][1];
                }
                break;
            }
            // cout<<"sum "<<sum<<endl;
        }
        return res;
    }
};