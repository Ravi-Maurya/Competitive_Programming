#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    long long int res = 0;
    for(int x=1;x<=n;x++){
        int y = x + b - c;
        int z = x + a - d;
        int w = a + y - d;
        if(1<=y && y<=n && 1<=z && z<=n && 1<=w && w<=n)
            res++;
    }
    res *= n;//for middle element;
    cout<<res<<"\n";
    return 0;
}