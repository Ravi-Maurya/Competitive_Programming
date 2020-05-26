#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    ll res = 0;
    if(a>(b-c) && (n-b)>=0){
        res += floor((n-c)/(b-c));
        n -= res*(b-c);
    }
    res += floor(n/a);
    cout<<res<<"\n";
    return 0;
}