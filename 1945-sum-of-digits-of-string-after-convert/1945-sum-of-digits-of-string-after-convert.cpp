class Solution {
public:
    string sum_digits(string n)
    {
        int val = 0;
        for(int i=0;i<n.length();i++)
        {
            val += (n[i]-'0');
            
        }
        return to_string(val);
    }
    int getLucky(string s, int k) {
        string num="";
        for(int i=0; i<s.length(); i++)
        {
            char temp = s[i] - 'a' + 1;
            num = num + to_string(temp);
        }
        while(k--)
        {
            num = sum_digits(num);
        }
        return stoi(num);
    }
};