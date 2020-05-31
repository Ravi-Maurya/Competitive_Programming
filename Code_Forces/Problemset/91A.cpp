#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll l,r,i;
    cin>>l>>r;
    vector<ll>dp(1200);dp[1]=4;dp[2]=7;
    ll k=3;
    ll ans=0;
    for(i=1;i<=512;i++){
       dp[k++]=dp[i]*10+4;
       dp[k++]=dp[i]*10+7;
    }
    k=1;
    i=l;
    while(i<=r){
        if(i>dp[k])
            k++;
        else{
            ans += (dp[k]*min(r-i+1,dp[k]-i+1));
            i=dp[k]+1;
      }
    }
    cout<<ans<<endl;
    return 0;
}