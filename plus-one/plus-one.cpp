class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        for(int i = digits.size()-1; i>=0; i--)
        {
            int temp = digits[i] + 1;
            if(temp >= 10)
            {
                temp = temp%10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            digits[i] = temp;
            if(carry == 0)
                return digits;
        }
        if(carry > 0)
        {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};