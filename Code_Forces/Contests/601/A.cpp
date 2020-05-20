#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> check = {-5,-2,-1,1,2,5};
    int t;
    scanf("%d",&t);
    for(int test=1; test<=t; test++){
        long long int a,b,diff,res;
        scanf("%lld%lld",&a,&b);
        diff = abs(a-b);
        res = (diff/5) + (diff%5)/2 + ((diff%5)%2);
        cout<<res<<"\n";
    }
    return 0;
}