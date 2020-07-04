class DSU{
    private:
    vector<int> parent;
    vector<int> rank;
    int count;
    public:
    DSU(int n){
        count = 0;
        parent.resize(n,-1);
        rank.resize(n,0);
    }
    
    int Find(int u){
        if(parent[u]!=u)
            parent[u] = Find(parent[u]);
        return parent[u];
    }
    
    void Union(int u, int v){
        u = Find(u); v = Find(v);
        if(u!=v){
            if(rank[u]<rank[v])
                swap(u,v);
            parent[v] = u;
            if(rank[u]==rank[v])
                rank[u]++;
            count--;
        }
        return;
    }
    
    int getCount(){
        return count;
    }
    
    bool check(int u){
        return parent[u]>=0;
    }
    
    void init(int u){
        if(parent[u] == -1){
            parent[u] = u;
            count++;
        }
    }
};

class Solution {
public:
    int dirs[5] = {-1,0,1,0,-1};
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> res;
        DSU ds(n*m);
        for(auto& pos: positions){
            int r = pos[0];
            int c = pos[1];
            int u = r*n + c;
            ds.init(u);
            for(int i=0; i<4; i++){
                int nr = r + dirs[i];
                int nc = c + dirs[i+1];
                int v = nr*n + nc;
                if(nr>=0 && nc>=0 && nr<m && nc<n && ds.check(v))
                    ds.Union(u,v);
            }
            res.push_back(ds.getCount());
        }
        return res;
    }
};