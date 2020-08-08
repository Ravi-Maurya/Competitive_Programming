class Solution {
public:
    int dp[605][105][105];
    void convert(vector<string>& strs, vector<int>& ones, vector<int>& zeroes){
        for(int i=0; i<strs.size(); i++){
            string st = strs[i];
            for(int j=0; j<st.size(); j++){
                int x = st[j]-'0';
                if(x==1)
                    ones[i]++;
                else
                    zeroes[i]++;
            }
        }
        return;
    }
    
    int recursion(vector<int>& ones, vector<int>& zeroes, int idx, int n, int m){
        if(idx>=zeroes.size()){
            return 0;
        }
        if(dp[idx][n][m]!=-1)
            return dp[idx][n][m];
        if(ones[idx]<=n && zeroes[idx]<=m){
            return dp[idx][n][m] = max(recursion(ones,zeroes,idx+1,n,m), 1 + recursion(ones,zeroes,idx+1,n-ones[idx],m-zeroes[idx]));
        }
        return dp[idx][n][m] = recursion(ones,zeroes,idx+1,n,m);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<int> ones(size,0), zeroes(size,0);
        convert(strs,ones,zeroes);
        memset(dp,-1,sizeof(dp));
        return recursion(ones,zeroes,0,n,m);
    }
};



class Solution {
public:
    int dp[605][105][105];
    void convert(vector<string>& strs, vector<int>& ones, vector<int>& zeroes){
        for(int i=0; i<strs.size(); i++){
            string st = strs[i];
            for(int j=0; j<st.size(); j++){
                int x = st[j]-'0';
                if(x==1)
                    ones[i]++;
                else
                    zeroes[i]++;
            }
        }
        return;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<int> ones(size,0), zeroes(size,0);
        convert(strs,ones,zeroes);
        memset(dp,0,sizeof(dp));
        for(int i=0; i<=n; i++)
            for(int j=0; j<=m; j++){
                if(ones[0]<=i && zeroes[0]<=j)
                    dp[0][i][j] = 1;
                else
                    dp[0][i][j] = 0;
            }
        for(int i=1; i<size; i++){
            for(int j=0; j<=n; j++){
                for(int k=0; k<=m; k++){
                    if(ones[i]<=j && zeroes[i]<=k){
                        dp[i][j][k] = max(dp[i-1][j][k], 1 + dp[i-1][j-ones[i]][k-zeroes[i]]);
                    }
                    else{
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            }
        }
        return dp[size-1][n][m];
    }
};