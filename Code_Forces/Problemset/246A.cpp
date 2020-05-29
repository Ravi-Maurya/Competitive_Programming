#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    int res = 0;
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        if(t<= 5-k)
            res++;
    }
    res = res/3;
    cout<<res<<"\n";
    return 0;
}