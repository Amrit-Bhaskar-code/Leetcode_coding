class Solution {
public:
    int climbStairs(int n) {
        vector<int> arr;
        arr.push_back(1);
        arr.push_back(2);
        
        int top = 2;
        
        while(top<n)
        {
            arr.push_back(arr[top-2]+ arr[top-1]);
            top++;
        }
        return arr[n-1];
    }
};