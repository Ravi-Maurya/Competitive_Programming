#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int s = (n*(n+1))/2;
    int k = m%s;
    int res = 0;
    // cout<<k<<"\n";
    if(k>0){
        for(int i=n-1;i>=1;i--){
            if((i*i + i - 2*k)<=0){
                // cout<<i<<"\n";
                res = k - (i*(i+1))/2;
                break;
            }
        }
    }
    cout<<res<<"\n";
    return 0;
}