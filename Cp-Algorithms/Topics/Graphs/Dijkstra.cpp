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

vector<vector<pair<int,int>>> adjList;//(u->(wt,v))
int n;

vector<int> dijkstra(int source){ // O(Elog(V))
    minheap(pll) pq;
    vector<int> distance(n,inf),parent(n,-1);//parent for backtracking
    pq.push(make_pair(0,source));
    distance[source] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        int dwt = pq.top().first;
        if(dwt!=distance[u])
            continue;
        for(auto destination: adjList[u]){
            int v = destination.second;
            int wt = destination.first;
            if(distance[v]> distance[u]+wt){
                distance[v] = distance[u] + wt;
                parent[v] = u;
                pq.push(make_pair(distance[v],v));
            }
        }
    }
    return distance;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}