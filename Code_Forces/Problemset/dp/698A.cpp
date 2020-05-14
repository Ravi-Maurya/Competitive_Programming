#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
// https://codeforces.com/problemset/problem/698/A
int vacations(vector<int>& arr, int n){
    vector<int> dp(3,0);
    for(int i=1; i<=n; i++){
        int a = *max_element(dp.begin(),dp.end());
        int b = dp[1];
        int c = dp[2];
        if(arr[i-1]==1 || arr[i-1]==3){
            b = 1 +max(dp[0], dp[2]);
        }
        if(arr[i-1]==2 || arr[i-1]==3){
            c = 1 + max(dp[1],dp[0]);
        }
        dp[0] = a;
        dp[1] = b;
        dp[2] = c;
    }
    return n - *max_element(dp.begin(),dp.end());
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<vacations(arr,n)<<"\n";
    return 0;
}