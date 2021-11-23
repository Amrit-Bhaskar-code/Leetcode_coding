class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int h = s.length()-1;
        char c_l, c_h;
        while(l<h)
        {
            while(!isalnum(s[l]) && l<h)
            {
                l++;
            }
            c_l = s[l];
            if(c_l<'a')
            {
                c_l = c_l + 32;
            }
            while(!isalnum(s[h]) && h>l)
            {
                h--;
            }
            c_h = s[h];
            if(c_h<'a')
            {
                c_h = c_h + 32;
            }
            if(c_l!=c_h)
                return false;
            l++;
            h--;
        }
        return true;
        // string temp;
        // char c;
        // bool b;
        // for(int i=0;i<s.length();i++)
        // {
        //     c = s[i];
        //     b = isalnum(c);
        //     if(c<'a' && b)
        //     {
        //         c = c + 32;
        //     }
        //     if(b)
        //     {
        //         temp = temp + c;
        //     }
        // }
        // int l = 0;
        // int h = temp.length()-1;
        // while(l<h)
        // {
        //     if(temp[l]!=temp[h])
        //         return false;
        //     l++;
        //     h--;
        // }
        // //cout<<temp;
        // return true;
    }
};