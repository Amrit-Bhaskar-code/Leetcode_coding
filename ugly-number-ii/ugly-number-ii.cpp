class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1) return 1; // base case
        vector<int> a(n);
        a[0] = 1;
        int t1,t2,t3;
        t1 = t2 = t3 = 0;
        for(int i=1;i<n;i++)
        {
            a[i] = min(2*a[t1], min(3*a[t2], 5*a[t3]));
            if(a[i] == 2*a[t1]) t1++;
            if(a[i] == 3*a[t2]) t2++;
            if(a[i] == 5*a[t3]) t3++;
        }
        return a[n-1];
    }
};