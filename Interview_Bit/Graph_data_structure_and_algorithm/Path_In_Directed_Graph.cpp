int Solution::solve(int A, vector<vector<int> > &B) {
    unordered_map<int, unordered_set<int>> graph;
    for(int i=0; i<B.size(); i++)
        graph[B[i][0]].insert(B[i][1]);
    if(graph.find(1)==graph.end())
        return 0;
    queue<int> q;
    unordered_set<int> visited;
    q.push(1);
    visited.insert(1);
    while(q.size()){
        auto curr = q.front(); q.pop();
        if(curr == A)
            return 1;
        if(graph.find(curr)==graph.end())
            continue;
        for(auto v: graph[curr]){
            if(visited.find(v)==visited.end()){
                visited.insert(v);
                q.push(v);
            }
        }
    }
    return 0;

}
