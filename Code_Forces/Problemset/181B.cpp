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

int graph[50][50],n,m;
bool visited[50];
vector<vector<int>> c[50];

vector<int> curr;

int dfs(int v){
    visited[v] =true;
    curr.push_back(v);
    for(int i=1;i<=n; i++){
        if(graph[v][i] && !visited[i])
            dfs(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    memset(graph,0,sizeof(graph));
    memset(visited,0,sizeof(visited));
    cin>>n>>m;
    rep(m){
        int a,b;
        cin>>a>>b;
        graph[a][b] = graph[b][a] = 1;
    }
    for(int i=1; i<=n ;i++){
        if(!visited[i]){
            curr.clear();
            dfs(i);
            c[curr.size()].push_back(curr);
        }
    }
    vector<vector<int>> res = c[3];
    for(int i=4;i<50;i++){
        if(c[i].size()!=0){
            cout<<-1<<"\n";
            return 0;
        }
    }
    if(c[2].size() > c[1].size()){
        cout<<-1<<"\n";
        return 0;
    }
    for(int i=0;i<c[2].size();i++){
        vector<int> tmp;
        tmp.push_back(c[2][i][0]);
        tmp.push_back(c[2][i][1]);
        tmp.push_back(c[1][i][0]);
        res.push_back(tmp);
    }
    for(int i=c[2].size(); i<c[1].size(); i+=3){
        vector<int>tmp;
        for(int j=0;j<3;j++){
            tmp.push_back(c[1][i+j][0]);
        }
        res.push_back(tmp);
    }
    for(int i=0;i<n/3;i++){
        for(int j=0;j<3;j++)
            cout<<res[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}