class DSU{
    public:
    vector<int> parent;
    vector<int> rank;
    int count;
    DSU(int V){
        count = V;
        parent.resize(V+1);
        rank.resize(V+1);
        for(int i=0; i<=V; i++){
            rank[i] = 0;
            parent[i] = i;
        }
    }
    
    int Find(int u){
        if(u!=parent[u])
            parent[u] = Find(parent[u]);
        return parent[u];
    }
    
    void Union(int u, int v){
        u = Find(u);
        v = Find(v);
        if(u==v)
            return;
        count -= 1;
        if(rank[u]<rank[v])
            swap(u,v);
        parent[v] = u;
        if(rank[u]==rank[v])
            rank[u]++;
        return;
    }
    
    int getcount(){
        return count;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU ds(n);
        for(auto & edge: edges)
            ds.Union(edge[0],edge[1]);
        return ds.getcount();
    }
};