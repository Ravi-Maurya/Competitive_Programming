#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
# define INF 0x3f3f3f3f

unordered_map<int,set<int>> adjList;

void recursive_dfs(int u, vector<bool>& visited){ //O(V+E)
    visited[u] = 1;
    cout<<u<<"\n";
    for(int v:adjList[u]){
        if(!visited[v])
            recursive_dfs(v,visited);
    }
}

vector<int> bfs(int source){//O(V+E)
    unordered_map<int,bool> visited;
    queue<int> q;
    q.push(source);
    visited[source] = true;
    vector<int> res;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        res.push_back(u);
        for(auto v:adjList[u]){
            if(visited.find(v)==visited.end()){
                q.push(v);
                visited[v] = true;
            }
        }
    }
    return res;
}

vector<int> dfs(int source){ //O(V+E)
    unordered_map<int,bool> visited;
    stack<int> s;
    s.push(source);
    vector<int> res;
    while (!s.empty()){
        int u = s.top();
        s.pop();
        if(visited.find(u)==visited.end()){
            res.push_back(u);
            visited[u] = true;
            for(auto v:adjList[u])
                if(visited.find(v)==visited.end())
                    s.push(v);
        }
    }
    return res;
}

vector<int> topological_sort(int V){
    vector<int> inDegree(V,0);
    for(int u=0; u<V; u++)
        for(auto it = adjList[u].begin(); it!=adjList[u].end(); it++)
            inDegree[*it]++;
    
    queue<int> q;
    for(int u=0; u<V; u++)
        if(inDegree[u]==0)
            q.push(u);
    
    int count = 0;
    vector<int> topSort;
    while (!q.empty()){
        int u = q.front();
        q.pop;
        topSort.push_back(u);
        for(auto it = adjList[u].begin(); it!=adjList[u].end(); it++)
            if(--inDegree[*it]==0)
                q.push(*it);
        count++;
    }
    if(count != V)//Cycle exists
        return {};
    return topSort;
}

vector<pair<int,int>> adjListWeighted[];//u->(wt,v)

vector<int> dijkstra(int n, int source){ // O(Elog(V))
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> distance(n,INF);
    pq.push(make_pair(0,source));
    distance[source] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(auto destination: adjListWeighted[u]){
            int v = destination.second;
            int wt = destination.first;
            if(distance[v]> distance[u]+wt){
                distance[v] = distance[u] + wt;
                pq.push(make_pair(distance[v],v));
            }
        }
    }
    return distance;
}

void floydd(vector<vector<int>> adjMatrix){ // O(n**3)
    int v = adjMatrix.size();
    for(int k=0; k<v; k++)
        for(int i=0; i<v; i++)
            for(int j=0; j<v; j++)
                if(adjMatrix[i][k] + adjMatrix[k][j] < adjMatrix[i][j])
                    adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
}

vector<pair<int,pair<int,int>>> edges;//wt -> (u,v)

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

int kruskal(int V){
    int wt_mst = 0;
    sort(edges.begin(), edges.end());
    DisjointSets ds(V);
    for(auto it = edges.begin(); it!=edges.end(); it++){
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.Find(u);
        int set_v = ds.Find(v);
        if(set_u != set_v){
            cout<<u<<" "<<v<<"\n";
            wt_mst += it->first;
            ds.Union(set_u, set_v);
        }
    }
    return wt_mst;
}

bool isCycle(int V){
    DisjointSets ds(V);
    for(auto it = edges.begin(); it!=edges.end(); it++){
        int u = ds.Find(it->second.first);
        int v = ds.Find(it->second.second);
        if(u==v)
            return 1;
        ds.Union(u,v);
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}