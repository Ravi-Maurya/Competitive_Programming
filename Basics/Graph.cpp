#include <bits/stdc++.h>
using namespace std;
class Graph{
public:
    unordered_map<int,set<int>> adjList;
    Graph();
    void add_edge(int u, int v, bool isBidirectional);
    vector<int> bfs(int source);
    vector<int> dfs(int source);

};

Graph::Graph(){
    adjList.clear();
}

void Graph::add_edge(int u, int v, bool isBidirectional=true){
    adjList[u].insert(v);
    if(isBidirectional)
        adjList[v].insert(u);
}

vector<int> Graph::bfs(int source){
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

vector<int> Graph::dfs(int source){
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


int main(){
    Graph g;
    g.add_edge(1,2);
    g.add_edge(1,3);
    g.add_edge(1,4);
    g.add_edge(1,5);
    g.add_edge(2,5);
    g.add_edge(3,4);
    vector<int> ans = g.bfs(2);
    cout<<"BFS"<<'\n';
    for(auto x:ans)
        cout<<x<<" ";
    ans = g.dfs(2);
    cout<<"\nDFS"<<'\n';
    for(auto x:ans)
        cout<<x<<" ";
    return 0;
}