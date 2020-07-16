class Solution {
public:
    const int mod = 1e9 + 7;
    long long int concat(vector<int>& arr, int k){
        long long int curr = 0, glob = 0;
        int n = arr.size();
        for(int i=0; i<k*n; i++){
            curr += arr[i%n];
            if(glob<curr)
                glob = curr;
            if(curr<0)
                curr = 0;
        }
        return glob%mod;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();
        if(n==0)
            return 0;
        long long int sum = concat(arr,1);
        if(k==1)
            return sum;
        long long int Sum = 0, sum2 = concat(arr,2);
        for(auto x: arr)
            Sum += x;
        if(Sum<0)
            return sum2;
        long long res = (sum2 + (long long)(k-2) * Sum)%mod;
        return res;
    }
};