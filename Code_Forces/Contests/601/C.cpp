#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> count(n+1,0),res(n+1),visited(n+1,0);
    map<int,vector<pair<int,int>>> mp;
    for(int i=0; i<n-2; i++){
        int x,y,z;
        cin>>x>>y>>z;
        count[x]++;
        count[y]++;
        count[z]++;
        mp[x].push_back({y,z});
        mp[y].push_back({z,x});
        mp[z].push_back({x,y});
    }
    int st = 0;
    for(int i=0; i<n; i++)
        if(count[i+1]==1)
            st = i+1;
    res[1] = st;
    visited[st] = 1;
    res[2] = (mp[mp[st][0].first].size() == 2)? mp[st][0].first: mp[st][0].second;
    visited[res[2]] = 1;
    for(int i=3; i<=n; i++){
        for(auto curr: mp[res[i-1]]){
            if(curr.first == res[i-2] || curr.second==res[i-2]){
                int val = (curr.first == res[i-2])?curr.second: curr.first;
                if(visited[val]==0){
                    res[i] = val;
                    visited[val] = 1;
                }
            }
        }
    }
    for(int i=0; i<n; i++)
        cout<<res[i+1]<<" ";
    return 0;
}