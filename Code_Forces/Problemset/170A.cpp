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
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> lang_to_people(m+1);
    rep(n){
        ll k ;
        cin>>k;
        while(k--){
            ll lang;
            cin>>lang;
            lang_to_people[lang].push_back((i+1));
        }
    }
    DisjointSets ds(n);
    bool flag = false;
    for(ll i=1; i<=m; i++){
        ll size = lang_to_people[i].size();
        if(size>0)
            flag =true;
        for(ll j=1; j<size; j++){
            ds.Union(lang_to_people[i][0],lang_to_people[i][j]);
        }
    }
    // cout<<flag<<" ";
    unordered_map<ll,ll> ump;
    for(ll i=1; i<=n; i++){
        ump[ds.Find(ds.parent[i])]++;
    }
    ll t = ump.size();
    if(t==1){
        cout<<0<<"\n";
        return 0;
    }
    if(t==n && !flag){
        cout<<n<<"\n";
        return 0;
    }
    ll prod = INT_MAX;
    for(auto& [p,val]:ump){
        if(prod>val)
            prod = val;
    }
    cout<<((t-1)*prod)<<"\n";
    return 0;
}