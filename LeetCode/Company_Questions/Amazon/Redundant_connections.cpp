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

    bool Union(int u, int v){
        u = Find(u);
        v = Find(v);
        if(u==v)
            return false;
        else if(rank[u] < rank[v])
            parent[u] = v;
        else if(rank[u] > rank[v])
            parent[v] = u;
        else{
            parent[v] = u;
            rank[u]++;
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSets ds(1001);
        for(auto edge: edges){
            if(!ds.Union(edge[0],edge[1]))
                return edge;
        }
        return {};
    }
};