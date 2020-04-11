#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        long long int res = 0;
        cin>>n;
        vector<long long int> arr(n);
        vector<vector<pair<unsigned long long int,long long int>>> dp(n,vector<pair<unsigned long long int,long long int>>(n,make_pair(0,0)));
        for(int i=0; i<n; i++){
            cin>>arr[i];
            dp[i][i].first =  arr[i];
            dp[i][i].second = ((abs(arr[i])%4 != 2)? 1 : 0);
        }
        for(int i=(n-2); i>=0; i--){
            for(int j=(i+1);j<n;j++){
                dp[i][j].first = dp[i+1][j].first * abs(arr[i]);
                dp[i][j].second = dp[i+1][j].second + dp[i][j-1].second - dp[i+1][j-1].second + ((dp[i][j].first %4 != 2)?1:0);
            }
        }
        cout<<dp[0][n-1].second<<"\n";
    }

    return 0;
}