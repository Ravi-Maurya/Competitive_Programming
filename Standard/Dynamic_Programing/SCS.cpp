#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

string scs(string a, string b){
    int m = a.size(), n = b.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0)
                dp[i][j] = j;
            else if(j==0)
                dp[i][j] = i;
            else if(a[i-1]==b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    int idx = dp[m][n];
    string res(idx+1,'\0');
    int i = m, j = n;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            res[idx-1] = a[i-1];
            i--;j--;idx--;
        }
        else if(dp[i-1][j]<dp[i][j-1]){
            res[idx-1] = a[i-1];
            i--;idx--;
        }
        else{
            res[idx-1] = b[j-1];
            j--;idx--;
        }
    }
    while(i>0){
        res[idx-1] = a[i-1];
        i--;idx--;
    }
    while(j>0){
        res[idx-1] = b[j-1];
        j--;idx--;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}