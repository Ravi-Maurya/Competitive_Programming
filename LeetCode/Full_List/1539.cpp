class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        if(n==0 || arr[0]>k)
            return k;
        if(arr[n-1]<n+k)
            return n+k;
        int l = k+1 , h = k+n;
        while(l<=h){
            int mid = l + (h-l)/2;
            int diff = mid - k;
            if(arr[diff-1]>=mid)
                h = mid-1;
            else
                l = mid+1;
        }
        return l-1;
    }
};