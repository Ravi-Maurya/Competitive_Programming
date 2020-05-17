#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n,k;
        cin>>n>>k;
        unordered_set<int> idx;
        vector<int> arr(n);
        for(int i = 0; i<n; i++){
            cin>>arr[i];
            if(arr[i]==k)
                idx.insert(i);
        }
        int res = 0;
        for(auto i: idx){
            if(i+k-1>=n)
                continue;
            int j = i+k-1;
            int test = k;
            bool flag = true;
            for(int x = i; x<=j; x++){
                if(arr[x]!=test--){
                    flag = false;
                    break;
                }
            }
            if(flag)
                res++;
        }
        cout<<"Case #"<<test<<": "<<res<<"\n";
    }
    return 0;
}