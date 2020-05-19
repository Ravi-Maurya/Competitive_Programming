#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

long long int helper(long long int a){
    long long int mn= 10, mx = 0;
    while(a){
        long long int tmp = a%10;
        a /= 10;
        if(tmp<mn)
            mn = tmp;
        if(tmp>mx)
            mx = tmp;
    }
    return mn*mx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test<=t; test++){
        long long int a, k;
        cin>>a>>k;
        k--;
        while(k--){
            auto curr = helper(a);
            if(curr==0)
                break;
            a += curr;
        }
        cout<<a<<"\n";
    }
    return 0;
}