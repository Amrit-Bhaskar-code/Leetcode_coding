#include <string>
class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1=="0" && num2=="0")
        {
            return "0";
        }
        if(num1=="0")
            return num2;
        if(num2=="0")
            return num1;
        
        int l1 = num1.length()-1;
        int l2 = num2.length()-1;
        int carry = 0;
        string res = "";
        while(l1>=0 || l2>=0 || carry)
        {
            int sum = 0;
            if(l1>=0)
            {
                sum+=(num1[l1]-'0');
                l1--;
            }
            if(l2>=0)
            {
                sum+=(num2[l2]-'0');
                l2--;
            }
            sum += carry;
            carry = sum/10;
            sum = sum%10;
            res = res + to_string(sum);
            
        }
        reverse(res.begin(), res.end());
        return res;
    }
};