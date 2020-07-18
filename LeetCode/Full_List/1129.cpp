class Solution {//copied
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        
        if(n==1) return {0};
        
        vector<vector<pair<int, char>>> graph(n, vector<pair<int, char>>());
        
        for(vector<int> edge : red_edges){
            graph[edge[0]].push_back(make_pair(edge[1], 'r'));
        }
        for(vector<int> edge : blue_edges){
            graph[edge[0]].push_back(make_pair(edge[1], 'b'));
        }

        
        queue<pair<int, pair<char, int> >> q;
        
        q.push(make_pair(0, make_pair('r', 0)));
        q.push(make_pair(0, make_pair('b', 0)));
        
        vector<bool> visr(n, false);
        vector<bool> visb(n, false);
        
        vector<int> ans(n, -1);
        ans[0] = 0;
        
        
        while(!q.empty()){
            
            auto value = q.front();
            q.pop();
            
            int& node = value.first;
            char& color = value.second.first;
            int& height = value.second.second;
                        
            for(auto& n : graph[node]){
                
                if( (n.second=='b' && !visb[n.first]) || (n.second=='r' && !visr[n.first]))
                {
                    if(color != n.second) {
                        
                        ans[n.first] = ans[n.first]==-1? height + 1 : min(ans[n.first], height + 1);
                        q.push(make_pair(n.first, make_pair(n.second, height + 1)));
                        if(color == 'b')
                            visb[node] = true;
                        else
                            visr[node] = true;
                    }
                }
            }
        }
            
        return ans;
    }
};