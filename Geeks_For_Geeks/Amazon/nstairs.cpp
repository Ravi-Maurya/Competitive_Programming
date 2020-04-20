#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n;
        cin>>n;
        int res = (n>>1);
        res += 1;
        cout<<res<<"\n";
        // downcode is also accepted
        // vector<long long> arr(n+1,0);
        // arr[0]=1;
        // for(int i=1;i<=n;i++)
        //     arr[i] += arr[i-1];
        // for(int i=2; i<=n; i++)
        //     arr[i] += arr[i-2];
        // cout<<arr[n]<<"\n";
    }
    return 0;
}