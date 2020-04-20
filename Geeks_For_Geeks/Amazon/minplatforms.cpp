#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

bool compare(pair<int,int> a, pair<int,int> b){
    return a.second<=b.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n;
        cin>>n;
        vector<pair<int,int>> intervals(n);
        for(int i=0;i<n;i++)
            cin>>intervals[i].first;
        for(int i=0;i<n;i++)
            cin>>intervals[i].second;
        vector<int> platforms(2361,0);
        int res = 1;
        for(int i=0; i<n; i++){
            ++platforms[intervals[i].first];
            --platforms[intervals[i].second+1];
        }
        for(int i=1; i<2361; i++){
            platforms[i] = platforms[i] + platforms[i-1];
            res = max(res,platforms[i]);
        }
        cout<<res<<"\n";
    }
    return 0;
}