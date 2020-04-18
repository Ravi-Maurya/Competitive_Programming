#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    string s1, s2;
    cin>>s1;
    cin>>s2;
    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    for(int i=1;i<=n1; i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    string res = "";
    int i = n1, j = n2;
    while (i>=1 && j>=1 && dp[i][j]!=0){
        if(i-1>=0 && dp[i-1][j]==dp[i][j])
            i--;
        else if(j-1>=0 && dp[i][j-1]==dp[i][j])
            j--;
        else{
            res += s1[i-1];
            i--;
            j--;
        }
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
    return 0;
}