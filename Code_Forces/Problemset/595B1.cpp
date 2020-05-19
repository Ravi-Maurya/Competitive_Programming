#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test<=t; test++){
        int n;
        cin>>n;
        unordered_map<int,int> graph;
        for(int i=1;i<=n;i++){
            int tmp;
            cin>>tmp;
            graph[i] = tmp;
        }
        vector<int> res(n,0);
        unordered_set<int>visited;
        for(int u=1;u<=n;u++){
            unordered_set<int> ust;
            if(visited.count(u))
                continue;
            int v = graph[u];
            int count = 1;
            ust.insert(u);
            while(v!=u){
                count++;
                ust.insert(v);
                v = graph[v];
            }
            for(auto idx:ust){
                visited.insert(idx);
                res[idx-1] = count;
            }
        }
        for(int i=0; i<n; i++)
            cout<<res[i]<<" ";
        cout<<"\n";

    }
    return 0;
}