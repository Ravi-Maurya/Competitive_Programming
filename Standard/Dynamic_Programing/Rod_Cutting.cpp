#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int recursive(vector<int>& arr, int n){
    if(n<=0)
        return 0;
    int mx = INT_MIN;
    for(int i=0; i<n; i++)
        mx = max(mx, arr[i] + recursive(arr,n-1-i));
    return mx;
}

int cut_rod(vector<int>& arr){
    int n = arr.size();
    vector<int> dp(n+1,0);
    for(int i=1; i<=n; i++){
        int mx = INT_MIN;
        for(int j=0; j<i; j++)
            mx = max(mx,arr[j]+dp[i-1-j]);
        dp[i] = mx;
    }
    return dp[n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}