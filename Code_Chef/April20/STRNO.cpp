#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int primeFactors(int n){
    int res = 0;
    while(n%2 == 0){
        n = n/2;
        ++res;
    }
    for(int i = 3; i <= (int)(sqrt(n)); i += 2){
        while(n%i == 0){
            n = n/i;
            ++res;
        }
    }
    if(n>2)
        ++res;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 0; test<t; test++){
        // cout<<test;
        int x,k;
        cin>>x>>k;
        int tmp = primeFactors(x);
        if(k <= tmp)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}