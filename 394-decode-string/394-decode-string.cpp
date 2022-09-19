class Solution {
public:
    void stack_pop(stack <char> &st)
    {
        vector<char> vec;
        while(st.top()!='[')
        {
            char temp = st.top();
            st.pop();
            // vec.push_back(temp);
            vec.insert(vec.begin(), temp);
        }
        st.pop();
        string m = "";
        while(!st.empty() && st.top()-'0'<=9 && st.top()-'0'>=0)
        {
            m = m + st.top();
            st.pop();
        }
        int num = 0;
        for(int i = m.length()-1; i>=0; i--)
        {
            num = num*10 + (m[i]-'0');
        }
        // cout<<num<<endl;
        // for(int i=0;i<vec.size();i++)
        //     cout<<vec[i]<<" ";
        // cout<<endl;
        string final_str = "";
        for(int j=0; j<num; j++)
        for(int i=0;i<vec.size();i++)
        {
            st.push(vec[i]);
        }
    }
    
    string decodeString(string s) {
        stack <char> st;
        string ans = "";
        for(int i=0;i<s.length();i++)
        {
            
            if(s[i]==']')
            {
                stack_pop(st);
                continue;
            }
            st.push(s[i]);
        }
        while(!st.empty())
        {
          ans = ans + st.top();
        st.pop();
        }
        string ans_rev = "";
        for(int i =ans.length()-1; i>=0;i--)
        {
            ans_rev = ans_rev + ans[i];
        }
        return ans_rev;
    }
};