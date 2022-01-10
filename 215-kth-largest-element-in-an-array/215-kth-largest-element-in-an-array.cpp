class Solution {
public:
    void heapify(int a[], int n, int i)
    {
        int largest = i;
        int l = 2*i+1;
        int r = 2*i+2;
        
        if(l<n && a[l] > a[largest])
        {
            largest = l;
        }
        if(r<n && a[r] > a[largest])
        {
            largest = r;
        }
        if( largest != i)
        {
            swap(a[i], a[largest]);
            heapify(a, n, largest);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n  = nums.size();
        int arr[n];
        for(int i=0; i<n ;i++)
        {
            arr[i] = nums[i];
        }
        for(int i=n/2-1; i>=0; i--)
        {
            heapify(arr, n, i);
        }
        for(int i=n-1; i>n-k ;i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
        return arr[0];
        
    }
};