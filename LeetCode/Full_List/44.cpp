class Solution {
public:
    vector<vector<int>> dp;
    string cleaned(string p){
        int n = p.size();
        string res = "";
        res.push_back(p[0]);
        for(int i=1; i<n;i++){
            if(res[res.size()-1]==p[i] && p[i]=='*')
                continue;
            res.push_back(p[i]);
        }
        return res;
    }
    bool solve(string s, string p, int n, int m){
        if(dp[n][m]!=-1)
            return (dp[n][m]==0)?false:true;
        if(n==0 && m==0){
            dp[n][m] = 1;
            return true;
        }
        if(m==0){
            dp[n][m] = 0;
            return false;
        }
        if(n==0){
            if(p[m-1]=='*'){
                return dp[n][m] = solve(s,p,n,m-1);
            }
            return dp[n][m] = false;
        }
        if(s[n-1]==p[m-1] || p[m-1]=='?')
            return dp[n][m] = solve(s,p,n-1,m-1);
        if(p[m-1]=='*')
            return dp[n][m] = (solve(s,p,n,m-1) || solve(s,p,n-1,m));
        return dp[n][m] = false;
    }
    bool isMatch(string s, string p) {
        if(s.size()==0 && p.size()==0)
            return true;
        if(p.size()==0)
            return false;
        p = cleaned(p);
        dp.resize(s.size()+1, vector<int>(p.size()+1,-1));
        return solve(s,p,s.size(),p.size());
    }
};

class Solution {
public:
    string cleaned(string p){
        int n = p.size();
        string res = "";
        res.push_back(p[0]);
        for(int i=1; i<n;i++){
            if(res[res.size()-1]==p[i] && p[i]=='*')
                continue;
            res.push_back(p[i]);
        }
        return res;
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        if(n==0 && m==0)
            return true;
        if(m==0)
            return false;
        p = cleaned(p);
        m = p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        for(int j=1; j<=m;j++){
            if(p[j-1]=='*')
                dp[0][j] = dp[0][j-1];
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};