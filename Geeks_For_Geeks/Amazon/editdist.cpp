#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int p,q;
        cin>>p>>q;
        string s1,s2;
        cin>>s1>>s2;
        vector<vector<int>> dp(p+1, vector<int>(q+1));
        for(int i=0;i<=p;i++)
            dp[i][0] = i;
        for(int j=0; j<=q;j++)
            dp[0][j] = j;
        for(int i=1;i<=p;i++)
            for(int j=1;j<=q;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1+min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
            }
        cout<<dp[p][q]<<"\n";
    }
    return 0;
}