class Solution {
public:
    int mySqrt(int x) {
        // binary search
        if(x==0)
        {
            return x;
        }
        int l = 1;
        int h  = x;
        int m = 0;
        while(l<=h)
        {
            m = l + (h-l)/2;
            // cout<<m<<endl;
            // if(m*m == x)
            //     return m;
            if(m > x/m)
            {
                h = m-1;
            }
            else
            {
                if((m+1) > x/(m+1))
                {
                    return m;
                }
                l = m+1;
            }
            // cout<<l<<" "<<h<<endl;
        }
        return m;
    }
};