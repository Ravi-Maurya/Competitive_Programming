int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    unordered_map<int,set<int>> graph;
    int n = B.size();
    for(int i=0;i<n;i++)
        graph[B[i]-1].insert(C[i]-1);
    for(int v=0;v<A;v++){
        if(graph.find(v)!=graph.end()){
            set<int> visited;
            
            deque<int> bfs;
            for(auto x:graph[v])
                bfs.push_back(x);
            while(!bfs.empty()){
                int current = bfs.front();
                bfs.pop_front();
                visited.insert(current);
                if(current==v)
                    return 0;
                if(graph.find(current)!=graph.end() && graph[current].size()){
                    for(auto n: graph[current]){
                        if(visited.find(n)==visited.end())
                            bfs.push_back(n);
                    }
                }
            }
        }
    }
    return 1;
}
