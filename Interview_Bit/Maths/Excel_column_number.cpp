int Solution::titleToNumber(string A) {
    int n = A.size();
    int ans = 0,i;
    for(i=0;i<n;i++){
        ans *= 26;
        ans += A[i]-'A'+1;
    }
    return ans;
}


int Solution::titleToNumber(string A) {
    int n = A.size();
    long long int ans = 0;
    for(int i=n-1; i>=0; i--){
        int curr = A[i] - 'A' + 1;
        ans += (long long)pow(26, n-i-1) * curr;
    }
    return ans;
}
