#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

pair<int,int> helper(unsigned long long int a){
    int mn= INT_MAX, mx = INT_MIN;
    while(a){
        int tmp = a%10;
        a /= 10;
        if(tmp<mn)
            mn = tmp;
        if(tmp>mx)
            mx = tmp;
    }
    return {mn,mx};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test<=t; test++){
        unsigned long long int a, k;
        cin>>a>>k;
        k--;
        while(k--){
            auto curr = helper(a);
            a += curr.first*curr.second;
        }
        cout<<a<<"\n";
    }
    return 0;
}