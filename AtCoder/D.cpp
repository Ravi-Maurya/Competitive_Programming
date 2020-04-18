#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
 
long long int knapsack(vector<long long int>& wt, vector<long long int>& val, int n, int Weight){
    vector<long long int> dp(10e5);
    for(int i=1; i<=n; i++){
        for(int w=Weight; w>=0; w--){
            if(w>=wt[i-1])
                dp[w] = max(dp[w-wt[i-1]]+val[i-1], dp[w]);
        }
    }
    return dp[Weight];
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n, w;
    cin>>n>>w;
    vector<long long int> wt(n), val(n);
    for(int i=0;i<n;i++)
        cin>>wt[i]>>val[i];
    cout<<knapsack(wt, val, n, w)<<endl;
    return 0;
}