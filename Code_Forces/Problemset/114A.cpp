#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n,x,y;
    cin>>n>>x>>y;
    int res = ceil((n*y - x*100)/100.0);
    cout<<max(res,0)<<"\n";
    return 0;
}