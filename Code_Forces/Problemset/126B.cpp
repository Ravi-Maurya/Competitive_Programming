#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    double res = 0;
    for(int i=0; i<n; i++){
        int pi;
        cin>>pi;
        res += pi;
    }
    res = (res*1.0)/n;
    cout<<res<<"\n";
    return 0;
}