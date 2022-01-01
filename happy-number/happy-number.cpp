class Solution {
public:
    int util(int n)
    {
        int sum = 0;
        int temp;
        while(n>0)
        {
            temp = n%10;
            sum += temp*temp;
            n = n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int fast, slow;
        fast=slow=n;
        do
        {
         slow = util(slow);
         fast = util(fast);
         fast = util(fast);
         if(fast == 1)
         {
             return true;
         }
        }
        while(fast!=slow);
        return false;
    }
};