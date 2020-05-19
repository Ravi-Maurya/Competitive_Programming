#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
 
long long int helper(long long int h, vector<long long int>& height, vector<long long int>& prefix, long long int n, long long int a, long long int r, long long int m) {
    int pos = lower_bound(height.begin(), height.end(), h) - height.begin();
    long long int res = 0, k1 = h*pos - prefix[pos], k2 = prefix[n] - prefix[pos] - h*(n-pos);
    res = min(k1,k2);
    k1 -= res;
    k2 -= res;
    res *= m;
    res += k1*a;
    res += k2*r;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    long long int n,a,r,m;
    cin>>n>>a>>r>>m;
    vector<long long int> height(n),prefix(n+1,0);
    m = min(m,a+r);
    for(long long int i=0;i<n;i++){
        cin>>height[i];
    }
    sort(height.begin(), height.end());
    for(long long int i=0; i<n; i++)
        prefix[i+1] = prefix[i]+height[i];
    long long int res = (long long int)2e18 + 77;
    res = min(res,helper(prefix[n]/n, height, prefix, n, a, r, m));
    res = min(res,helper(prefix[n]/n+1 , height, prefix, n, a, r, m));
    for(int i=0; i<n; i++)
        res = min(res,helper(height[i] , height, prefix, n, a, r, m));
    cout<<res<<"\n";
    return 0;
}