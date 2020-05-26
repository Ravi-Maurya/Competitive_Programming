#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int p;
    cin>>p;
    p--;
    int res = 1;
    for(int i=2; i<p; i++)
        if(__gcd(i,p)==1)
            res++;
    cout<<res<<"\n";
    return 0;
}