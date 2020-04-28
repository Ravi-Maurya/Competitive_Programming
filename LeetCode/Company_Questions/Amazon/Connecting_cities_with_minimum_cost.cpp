#include <bits/stdc++.h>
using namespace std;

vector<pair<int,pair<int,int>>> edges;//wt -> (u,v)

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

int kruskal(int V){
    int wt_mst = 0;
    sort(edges.begin(), edges.end());
    DisjointSets ds(V);
    for(auto it = edges.begin(); it!=edges.end(); it++){
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.Find(u);
        int set_v = ds.Find(v);
        if(set_u != set_v){
            cout<<u<<" "<<v<<"\n";
            wt_mst += it->first;
            ds.Union(set_u, set_v);
        }
    }
    return wt_mst;
}