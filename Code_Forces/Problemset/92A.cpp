#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n,a,b;
    cin>>n>>a>>b;
    int res = 0;
    for(int i=n-1; i>=a; i--){
        int tmpb = n - i - 1;
        if(tmpb<=b)
            res++;
    }
    cout<<res<<"\n";
    return 0;
}