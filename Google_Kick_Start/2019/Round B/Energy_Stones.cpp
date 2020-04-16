#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

// 0-1 Knapsack + sort the given in such pattern that get max.

int dp[102][102*102];

bool compare(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    return a.first.first * b.second < b.first.first * a.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n;
        cin>>n;
        vector<pair<pair<int,int>,int>> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i].first.first>>arr[i].first.second>>arr[i].second;
        sort(arr.begin(),arr.end(),compare);
        for (int i = 1; i <= n; i++)
            for(int j = 0; j<= n*100; j++)
                dp[i][j] = 0;
        
        for (int i = 0; i < n; i++){
            for(int j = 0; j<= i*100; j++){
                dp[i+1][j + arr[i].first.first] = max(dp[i+1][j+arr[i].first.first], dp[i][j]+max(0,arr[i].first.second - j*arr[i].second));
                dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
            }
        }
        int res = 0;
        for(int j=0; j<=n*100; j++)
            res = max(res,dp[n][j]);
        cout<<"Case #"<<test<<": "<<res<<"\n";
    }
    return 0;
}