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

vector<int> bfs(int source){
    vector<int> distance(n,inf);
    deque<int> dq;
    dq.push_front(source);
    distance[source] = 0;
    while(!dq.empty()){
        int u = dq.front();dq.pop_front();
        for(auto edge: adjList[u]){
            int v = edge.second;
            int wt = edge.first;
            if(distance[v]>distance[u] + wt){
                distance[v] = distance[u] + wt;
                if(wt==1)
                    dq.push_back(v);
                else
                    dq.push_front(v);
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