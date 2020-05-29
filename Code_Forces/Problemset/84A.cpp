#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
typedef long long int ll;

bool check(int x){
    if(x==0)return false;
    while(x>0){
        int t = x%10;
        if(t!=4 && t!=7)
            return false;
        x /= 10;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    int count = 0;
    while(n>0){
        int t = n%10;
        if(t==4 || t==7)
            count++;
        n /= 10;
    }
    cout<< (check(count)?"YES\n":"NO\n");
    return 0;
}