#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<bool> dp(k+1);
    for(int stones =0 ;stones<=k; stones++){
        for(int i=0; i<n;i++){
            if(stones-arr[i]>=0 && !dp[stones-arr[i]])
                dp[stones] = true;
        }
    }
    puts(dp[k] ? "First": "Second");
    return 0;
}