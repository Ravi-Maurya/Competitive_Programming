int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    vector<int> sum_arr(n + 1, 0);
    for(int i=0; i<n; i++)
        sum_arr[i+1] = sum_arr[i] + A[i];
    int ans = INT_MIN;
    int j = -1, i = n-B;
    while(B--){
        int curr = 0;
        if (i<n){
            curr += sum_arr[n] - sum_arr[i];
        }
        if (j>=0){
            curr += sum_arr[j+1] - sum_arr[0];
        }
        j = (j+1)%n;
        i = (i+1)%n;
        ans = max(ans, curr);
    }
    return ans;
}
