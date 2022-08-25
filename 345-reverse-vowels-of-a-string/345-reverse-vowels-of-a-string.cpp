class Solution {
public:
    bool is_vowel(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        if(s.length()==0) return s;
        int l = 0, r = s.length()-1;
        while(l<r)
        {
            if(is_vowel(s[l]) && is_vowel(s[r]))
            {
                char temp = s[r];
                s[r] = s[l];
                s[l] = temp;
                l++; r--;
                continue;
            }
            if(!is_vowel(s[l]))
            {
                l++;
            }
            if(!is_vowel(s[r]))
            {
                r--;
            }
        }
        return s;
    }
};