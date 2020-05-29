#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int k,l,m,n,d;
    cin>>k>>l>>m>>n>>d;
    int res = 0;
    for(int i=1; i<=d; i++){
        if((i%k==0) || (i%l==0) || (i%m==0) || (i%n==0))
            res++;
    }
    cout<<res<<"\n";
    return 0;
}