class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=0;
        for(int i=num.size()-1; i>=0; i--)
        {
            int temp1 = 0;
            if(k>0)
            {
                temp1 = k%10;
                k = k/10;
            }
            
            int s = temp1 + num[i] + carry;
            carry = s/10;
            if(s>9)
                s = s%10;
            num[i] = s;
        }
        
        
        while(k>0)
        {
            // cout<<k<<" "<<carry<<endl;
            num.insert(num.begin(), (k%10 + carry)%10);
            carry = (k%10 + carry)/10;
            k = k/10;        
        }
        if(k==0 && carry>0)
        {
            num.insert(num.begin(), carry);
            carry = carry/10;
        }
        
        return num;
    }
};