int res;

int dfs(int u, vector<int> adjList[], int root){
    vector<int> v;
    for(auto x: adjList[u])
        if(x!=root)
            v.push_back(dfs(x,adjList,u));
    if(v.size()==0){
        res = max(res,1);
        return 1;
    }
    if(v.size()==1){
        res = max(res,v[0]+1);
        return 1+v[0];
    }
    sort(v.rbegin(),v.rend());
    res = max(res,v[0]+v[1]+1);
    return v[0]+1;
}

int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> adjList[n];
    int r = 0;
    for(int i=0;i<n;i++){
        if(A[i]==-1){
            r = i;
            continue;
        }
        adjList[A[i]].push_back(i);
        adjList[i].push_back(A[i]);
    }
    res = INT_MIN;
    dfs(0,adjList,-1);
    return res-1;
}




//////////////



vector<int> bfs(vector<vector<int>>& tree, int src){
    int n = tree.size();
    vector<int> dist(n, 0);
    vector<bool> vis(n, false);
    
    queue<int> queue;
    queue.push(src);
    vis[src] = true;

    while(not queue.empty()){
        auto front = queue.front();
        queue.pop();

        for(int v: tree[front]){
            if(!vis[v]){
                queue.push(v);
                dist[v] = dist[front]+1;
                vis[v] = true;
            }
        }
    }

    return dist;
}

int Solution::solve(vector<int> &parent) {
    int n = parent.size();
    vector<vector<int>> tree(n, vector<int>());

    int root = -1;
    for(int i=0; i<parent.size(); i++){
        if(parent[i] == -1){
            root = i;
            continue;
        }
        tree[parent[i]].push_back(i);
        tree[i].push_back(parent[i]);
    }

    auto dist = bfs(tree, root);
    int ind = max_element(dist.begin(), dist.end()) - dist.begin();

    dist = bfs(tree, ind);
    return *max_element(dist.begin(), dist.end());
}
