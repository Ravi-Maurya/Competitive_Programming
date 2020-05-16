#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

vector<pair<int,int>> edges;

struct DisjointSets{
    int *parent, *rank;
    int n;
    DisjointSets(int n){
        this->n = n;
        parent = new int[n+1];
        rank = new int[n+1];
        for(int i = 0; i<=n; i++){
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int Find(int u){
        if(u != parent[u])
            parent[u] = Find(parent[u]);
        return parent[u];
    }

    void Union(int u, int v){
        u = Find(u);
        v = Find(v);

        if(rank[u] > rank[v])
            parent[v] = u;
        else
            parent[u] = parent[v];
        if(rank[u]==rank[v])
            rank[v]++;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int tests;
    cin>>tests;
    for(int t = 1; t<=tests; t++){
        edges.clear();
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--;v--;
            edges.push_back({u,v});
        }
        int count = 0;
        DisjointSets ds(n);
        for(int i=0; i<m; i++){
            int u = edges[i].first;
            int v = edges[i].second;
            if(ds.Find(u)==ds.Find(v))
                continue;
            count++;
            ds.Union(u,v);
        }
        int rem = (n-1)- count;
        count += 2*rem;
        cout<<"Case #"<<t<<": "<<count<<"\n";
    }
    return 0;
}