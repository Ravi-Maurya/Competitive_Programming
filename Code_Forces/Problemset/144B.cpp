#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
typedef long long int ll;

int div(ll x){
    ll res = 0;
    while(x){
        res += x%10;
        x /= 10;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin >> n;
    ll num = -1;
    ll x = sqrt(n);
    for (ll j = x; j >= (x - 90) && j > 0; j--) {
        if ((j * j + div(j)*j - n) == 0)
        {num = j; break;}
    }
    cout << num << endl;
    return 0;
}