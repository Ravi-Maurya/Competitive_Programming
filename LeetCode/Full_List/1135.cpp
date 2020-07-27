class Solution {
public:
    struct DSU{
        int *parent, *rank;
        int n;
        DSU(int n){
            this->n = n;
            parent = new int[n+1];
            rank = new int[n+1];
            for(int i=0;i<=n; i++){
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
            if(rank[u]<rank[v])
                swap(u,v);
            parent[v] = u;
            if(rank[u]==rank[v])
                rank[u]++;
            return;
        }
        
        bool check(){
            for(int i=2; i<=n; i++){
                if(Find(1)!=Find(i))
                    return false;
            }
            return true;
        }
    };
    vector<pair<int,pair<int,int>>> edges;
    int kruskal(int n){
        int res = 0;
        sort(edges.begin(),edges.end());
        DSU ds(n);
        for(auto it = edges.begin(); it!=edges.end(); it++){
            int u = it->second.first;
            int v = it->second.second;
            u = ds.Find(u);
            v = ds.Find(v);
            if(u!=v){
                res += it->first;
                ds.Union(u,v);
            }
        }
        if(ds.check())
            return res;
        return -1;
        
    }
    int minimumCost(int N, vector<vector<int>>& connections) {
        for(auto arr: connections)
            edges.push_back({arr[2],{arr[0],arr[1]}});
        return kruskal(N);
    }
};