#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

// Simple Frequency prefix count

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        vector<vector<int>> dp(n+1,vector<int>(26,0));
        for(int i=0;i<n;i++){
            dp[i+1][s[i]-'A'] += 1;
            for(int j=0; j<26; j++)
                dp[i+1][j] += dp[i][j];
        }
        int res = 0;
        for(int query = 0; query<q; query++){
            int l,r;
            cin>>l>>r;
            int count_1 = 0, count_2=0;
            for(int i=0;i<26;i++){
                int x = dp[r][i] - dp[l-1][i];
                if(x%2 == 0)
                    count_2++;
                else
                    count_1++;
            }
            if(count_1 <=1)
                res++;
        }
        cout<<"Case #"<<test<<": "<<res<<"\n";
    }
    return 0;
}