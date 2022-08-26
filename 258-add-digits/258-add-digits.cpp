class Solution {
public:
    int sum_digits(int n)
    {
        int res = 0;
        while(n>0)
        {
            res += (n%10);
            n /=10;
        }
        return res;
    }
    int addDigits(int num) {
        int res = 0;
        while(num>=10)
        {
            num = sum_digits(num);
        }
        return num;
    }
};