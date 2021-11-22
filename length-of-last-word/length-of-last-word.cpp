class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string> w;
        int start = 0;
        int i=0;
        int count = 0;
        int j = s.length()-1;
        while(isspace(s[j]))
           {
               j--;
           }  
        // cout<<s.substr(start, j+1)<<endl;
        string temp = s.substr(start, j+1);
        for(i=0; i<temp.length(); i++)
        {
            if(isspace(temp[i]))
            {
                w.push_back(temp.substr(start, i-start));
                start = i+1;
            }    
        }
         w.push_back(temp.substr(start, i-start));
        // for(i=0;i<w.size();i++)
        // {
        //     cout<<w[i]<<endl;
        // }
        return w[w.size()-1].length();
    }
};