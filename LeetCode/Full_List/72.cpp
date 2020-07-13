class Solution {
public:
    vector<vector<int>> dp;
    int solve(string& w1, string& w2, int n1, int n2){
        if(dp[n1][n2]!=-1)
            return dp[n1][n2];
        if(n2==0 && n1==0)
            return dp[n1][n2] = 0;
        if(n1==0)
            return dp[n1][n2] = n2;
        if(n2==0)
            return dp[n1][n2] = n1;
        if(w1[n1-1] == w2[n2-1])
            return dp[n1][n2] = solve(w1,w2,n1-1,n2-1);
        return dp[n1][n2] = (1 + min({solve(w1,w2,n1-1,n2),solve(w1,w2,n1,n2-1),solve(w1,w2,n1-1,n2-1)}));
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        if(n1==0)
            return n2;
        if(n2==0)
            return n1;
        dp.resize(n1+1,vector<int>(n2+1,-1));
        return solve(word1,word2,word1.size(),word2.size());
    }
};

class Solution {
public:
    vector<vector<int>> dp;
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        if(n1==0)
            return n2;
        if(n2==0)
            return n1;
        dp.resize(n1+1,vector<int>(n2+1,0));
        for(int i=1; i<=n1; i++)
            dp[i][0] = i;
        for(int j=1; j<=n2; j++)
            dp[0][j] = j;
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2;j++){
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
            }
        }
        return dp[n1][n2];
    }
};