class Solution {
public:
    unordered_map<string,multiset<string>> graph;
    vector<string> res;
    
    void dfs(string s){
        if(graph.count(s)){
            while(!graph[s].empty()){
                string dst = *graph[s].begin();
                graph[s].erase(graph[s].begin());
                dfs(dst);
            }
        }
        res.push_back(s);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto ticket: tickets){
            auto u = ticket[0];
            auto v = ticket[1];
            graph[u].insert(v);
        }
        dfs("JFK");
        reverse(res.begin(),res.end());
        return res;
    }
};