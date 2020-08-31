class DisjointSetUnion{
    public:
    vector<int> parent;
    vector<int> rank;
    int mx;
    DisjointSetUnion(int V){
        mx = 1;
        parent.resize(V+1);
        rank.resize(V+1);
        for(int i=0;i<=V;i++){
            parent[i] = i;
            rank[i] = 1;//for size of tree start with 1 instead of 0
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
        if(u==v)
            return;
        if(rank[u]<rank[v])//same for size
            swap(u,v);
        parent[v] = u;
        // if(rank[u]==rank[v])//do not check simply size[a] += size[b];
        rank[u] += rank[v];
        mx = max(rank[u],mx);
        return;
    }
};

class Solution {
public:
    int N = 20001;
    int largestComponentSize(vector<int>& A) {
        int n = A.size();
        DisjointSetUnion ds(N);
        unordered_map<int,int> ump;
        int res = 0;
        for(int i=0; i<n; i++){
            int x = A[i];
            for(int j=2; j*j<=x; j++){
                if(x%j==0){
                    if(ump.count(j)){
                        ds.Union(ump[j],i);
                    }
                    else{
                        ump[j] = i;
                    }
                    
                    if(ump.count(x/j)){
                        ds.Union(ump[x/j],i);
                    }
                    else{
                        ump[x/j] = i;
                    }
                }
            }
            if(ump.count(x)){
                ds.Union(ump[x],i);
            }
            else{
                ump[x] = i;
            }
        }
        return ds.mx;
    }
};