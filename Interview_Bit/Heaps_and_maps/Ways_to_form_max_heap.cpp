#define N 101
#define mod 1000000007
long long int dp[N];
long long int nCk[N][N];
int log_2[N];

void initialize(int n){
    for(int i=0;i<=n;i++)
        dp[i] = -1;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            nCk[i][j] = -1;
    for(int i=1;i<=n;i++)
        log_2[i] = (int)floor(log2(i));
}

long long int combinations(int n, int k){
    if(k>n)
        return 0;
    if(n<=1 || k==0)
        return 1;
    if(nCk[n][k] != -1)
        return nCk[n][k];
    nCk[n][k] = (combinations(n-1,k-1)%mod + combinations(n-1,k)%mod)%mod;
    return nCk[n][k];
}

int get_L(int n){
    if (n==1)
        return 0;
    int h = log_2[n];
    int num = 1<<h;
    int last = n-num+1;
    if(last>=num/2)
        return num -1;
    else
        return last + num/2 -1;
}

long long int nheaps(int n){
    if(n<=1)
        return 1;
    if(dp[n]!=-1)
        return dp[n];
    int left = get_L(n);
    int right = n-1-left;
    dp[n] = (combinations(n-1,left)%mod * nheaps(left)%mod * nheaps(right)%mod)%mod;
    return dp[n];
}

int Solution::solve(int A) {
    if(A<=1)
        return 1;
    initialize(A);
    return nheaps(A)%mod;
}
