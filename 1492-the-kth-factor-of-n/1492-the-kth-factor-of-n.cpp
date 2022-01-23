class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> res(n+1, 0);
        for(int i=1;i<=n;i++)
        {
            if(res[i]==0 && n%i==0)
            {
                // cout<<i<<" "<<res[i]<<endl;
                for(int j=1; i*j<=n; j++)
                {
                    if(n%(i*j)==0)
                    res[i*j] = 1;
                }
            }
        }
        int result;
        for(int i=1; i<n+1; i++)
        {
            // cout<<i<<" "<<res[i]<<endl;
            if(res[i]==1)
            {
                k--;
                result = i;
            }
            if(k==0)
                break;
        }
        if(k>0)
        {
            return -1;
        }
        return result;
    }
};