#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

#define ll long long int
#define pll pair<ll,ll> 
#define pls pair<ll,string>
#define psl pair<string,ll>
#define plc pair<ll,char>
#define pcl pair<char,ll>
#define pss pair<string,string>
#define maxheap(type) priority_queue<type>
#define minheap(type) priority_queue<type,vector<type>,greater<type>>
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define precise(x,y) fixed<<setprecision(y)<<x
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define rep(n) for(auto i=0; i<n; i++)

class DisjointSetUnion{
    public:
    vector<int> parent;
    vector<int> rank;
    DisjointSetUnion(int V){
        parent.resize(V+1);
        rank.resize(V+1);
        for(int i=0;i<=V;i++){
            parent[i] = i;
            rank[i] = 0;//for size of tree start with 1 instead of 0
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
        if(rank[u]==rank[v])//do not check simply size[a] += size[b];
            rank[u]++;
        return;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}