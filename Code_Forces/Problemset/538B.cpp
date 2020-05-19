#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
// https://codeforces.com/problemset/problem/538/B
vector<int> quasi(int n){
    vector<int> res;
    while(n>0){
        int tmp = n, m = 0, p =1;
        while(tmp){
            int remainder = tmp%10;
            tmp /= 10;
            if(remainder)
                m += p;
            p *= 10;
        }
        res.push_back(m);
        n -= m;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    auto res = quasi(n);
    cout<<res.size()<<"\n";
    for(auto& x: res)
        cout<<x<<" ";
    cout<<"\n";
    return 0;
}