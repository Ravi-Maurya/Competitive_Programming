#define MOD 1000000007
int Solution::nTriang(vector<int> &A) {
    int n = A.size();
    if (n<3) return 0;
    int i,j,k;
    sort(A.begin(),A.end());
    int ans = 0;
    for(i=n-1;i>0;i--){
        k = 0;
        j = i-1;
        while (k<j){
            if (A[k]+A[j]>A[i]){
                ans += j-k;
                ans %= MOD;
                j--;
            }
            else
                k++;
        }
    }
    return ans%MOD;
}
