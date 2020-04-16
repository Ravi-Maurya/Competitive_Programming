#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n,q,Xor=0,best=0;
        cin>>n>>q;
        set<int> odd;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            Xor ^= arr[i];
            if(__builtin_popcount(arr[i])%2)
                odd.insert(i);
        }
        cout<<"Case #"<<test<<": ";
        while(q--){
            int p,v;
            cin>>p>>v;
            Xor ^= arr[p];
            Xor ^= v;
            if(__builtin_popcount(arr[p])%2)
                odd.erase(p);
            if(__builtin_popcount(v)%2)
                odd.insert(p);
            arr[p] = v;
            int best;
            if(__builtin_popcount(Xor)%2){
                assert(odd.size());
                best = max(n - 1 - *odd.begin(), *odd.rbegin());
            }
            else
                best = n;
            cout<<best<<" ";
        }
        cout<<"\n";
    }
    return 0;
}