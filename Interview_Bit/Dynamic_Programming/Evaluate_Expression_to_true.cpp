const int mod = 1e3 + 3;
int Solution::cnttrue(string A) {
    int n = A.size();
    vector<vector<int>> True(n+1,vector<int>(n+1,0)), False(n+1,vector<int>(n+1,0));
    for(int i=0; i<n; i+=2){
        True[i][i] = (A[i]=='T');
        False[i][i] = (A[i]=='F');
    }
    for(int length = 3; length<=n; length+=2){
        for(int i=0; i<n-length+1; i++){
            int j = i+length-1;
            for(int k=i+1; k<j;k+=2){
                if(A[k]=='|'){
                    True[i][j] = (True[i][j]%mod + (True[i][k-1]*True[k+1][j])%mod + (True[i][k-1]*False[k+1][j])%mod + (False[i][k-1]*True[k+1][j])%mod)%mod;
                    False[i][j] = (False[i][j]%mod + (False[i][k-1]*False[k+1][j])%mod)%mod;
                }
                else if(A[k]=='&'){
                    True[i][j] = (True[i][j]%mod + (True[i][k-1]*True[k+1][j])%mod)%mod;
                    False[i][j] = (False[i][j]%mod + (False[i][k-1]*False[k+1][j])%mod  + (True[i][k-1]*False[k+1][j])%mod + (False[i][k-1]*True[k+1][j])%mod)%mod;
                }
                else if(A[k]=='^'){
                    True[i][j] = (True[i][j]%mod + (True[i][k-1]*False[k+1][j])%mod + (False[i][k-1]*True[k+1][j])%mod)%mod;
                    False[i][j] = (False[i][j]%mod + (False[i][k-1]*False[k+1][j])%mod + (True[i][k-1]*True[k+1][j])%mod )%mod;
                }
            }
        }
    }
    return True[0][n-1];
}
