vector<int> convert(int x){
    vector<int> res;
    while(x!=0){
        res.push_back(x%10);
        x = x/10;
    }
    if (res.size()==0)
        res.push_back(0);
    reverse(res.begin(),res.end());
    return res;
}

int Solution::solve(vector<int> &A, int B, int C) {
    vector<int> digit = convert(C);
    int d = digit.size();
    int n = A.size(),i;
    if (B>d || n==0) return 0;
    else if(B<d){
        if (A[0]==0 && B!=1){
            return (n-1)*pow(n,B-1);
        }
        else{
            return pow(n,B);
        }
    }
    else{
        bool flag = true;
        vector <int> dp(B+1,0);
        vector <int> lower(11,0);
        for(i=0;i<n;i++)
            lower[A[i]+1] = 1;
        for(i=1;i<=10;i++)
            lower[i] += lower[i-1];
        dp[0] = 0;
        for(i=1;i<=B;i++){
            int t = lower[digit[i-1]];
            dp[i]=dp[i-1]*n;
            if(i==1 && A[0]==0 && B!=1)
                t--;
            if (flag)
                dp[i]+=t;
            flag = (flag&(lower[digit[i-1]+1]==lower[digit[i-1]]+1));
        }
        return dp[B];
    }
}
