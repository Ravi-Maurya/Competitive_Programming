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

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSets ds(20000);
        for(auto& stone: stones)
            ds.Union(stone[0],stone[1]+10000);
        unordered_set<int> visited;
        for(auto& stone: stones)
            visited.insert(ds.Find(stone[0]));
        return n - visited.size();
    }
};