class Solution {
public:
    vector<vector<int>> dp;
    int solve(string& s, string& t, int n, int m){
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(m==0)
            return dp[n][m] = 1;
        if(n==0)// tat -> tatto not possible
            return dp[n][m] = 0;
        if(s[n-1]==t[m-1])
            return dp[n][m] = (solve(s,t,n-1,m-1)+solve(s,t,n-1,m));
        return dp[n][m] = solve(s,t,n-1,m);
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return solve(s,t,s.size(),t.size());
    }
};

class Solution {
public:
    vector<vector<long long int>> dp;
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        dp.resize(m+1,vector<long long int>(n+1,0));
        if(m==0)
            return 1;
        if(n==0)
            return 0;
        for(int j=0; j<=n; j++)
            dp[0][j] = 1;
        for(int i=1;i<=m; i++)
            for(int j=1;j<=n;j++){
                if(s[j-1]==t[i-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        return dp[m][n];
    }
};