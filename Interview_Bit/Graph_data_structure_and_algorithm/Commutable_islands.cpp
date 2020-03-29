class Graph{
public:
    vector<pair<pair<int,int>,int>> adjList;
    Graph();
    void add_edge(int u, int v, int wt);
    int find(vector<int> &parent, int i);
    void unionG(vector<int> &parent, vector<int> &rank, int x, int y);
    int kruskal(int V);
};

Graph::Graph(){
    adjList.clear();
}

void Graph::add_edge(int u, int v, int wt){
    adjList.push_back({{u,v},wt});
}

int Graph::find(vector<int> &parent, int i){
    if(parent[i]==i)
            return i;
        return find(parent,parent[i]);
}

void Graph::unionG(vector<int> &parent, vector<int> &rank, int x, int y){
    int xroot = find(parent,x);
    int yroot = find(parent,y);
    if(rank[xroot]<rank[yroot])
        parent[xroot] = yroot;
    else if(rank[xroot]>rank[yroot])
        parent[yroot] = xroot;
    else{
        parent[yroot] = xroot;
        rank[xroot] += 1;
    }
}

bool compare(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    return a.second<b.second;
}

int Graph::kruskal(int V){
    int res = 0,i=0,e=0;
    sort(adjList.begin(),adjList.end(),compare);
    vector<int> parent(V), rank(V,0);
    for(int j=0;j<V;j++)
        parent[j] = j;
    while (e<V-1){
        pair<pair<int,int>,int> p = adjList[i];
        i++;
        int x = find(parent,p.first.first);
        int y = find(parent,p.first.second);
        if(x!=y){
            e++;
            res += p.second;
            unionG(parent,rank,x,y);
        }
    }
    return res;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    Graph g;
    for(int i=0;i<B.size();i++)
        g.add_edge(B[i][0]-1,B[i][1]-1,B[i][2]);
    return g.kruskal(A);
}
