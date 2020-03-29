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
    for(int i=0;i<n;i++){
        if(A[i]==-1)
            continue;
        adjList[A[i]].push_back(i);
        adjList[i].push_back(A[i]);
    }
    res = INT_MIN;
    dfs(0,adjList,-1);
    return res-1;
}
