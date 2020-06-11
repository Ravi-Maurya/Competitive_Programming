#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
struct DSU{
    int *parent;
    int n;
    DSU(int n){
        this->n = n;
        parent = new int[n+1];
        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
    }

    int Find(int u){
        if(u != parent[u])
            parent[u] = Find(parent[u]);
        return parent[u];
    }

    void Union(int u, int v){//O(n)
        u = Find(u);
        v = Find(v);
        if(u!=v)
            parent[u] = v;
        return;
    }
};

struct DisjointSets{// DisjointSets ds(V);
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

    void Union(int u, int v){//O(logn)
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
    return 0;
}