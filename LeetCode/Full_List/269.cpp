class Solution {
public:
    string alienOrder(vector<string>& alien) {
        unordered_set<char> ust;
        for(auto& word: alien)
            for(auto& ch: word)
                ust.insert(ch);
        int n = alien.size();
        vector<int> indegree(26,0);
        vector<unordered_set<int>> graph(26);
        for(int i=0; i<n-1; i++){
            auto prev = alien[i], curr = alien[i+1];
            for(int j=0; j<min(prev.size(), curr.size()); j++){
                if(prev.size()>curr.size() && prev.substr(0,curr.size())==curr)
                    return "";// case when abc->ab which is not valid case as orderly ab->abc
                if(prev[j]!=curr[j]){// only considering first distinctive charachters
                    if(graph[prev[j]-'a'].insert(curr[j]-'a').second)//if not present previously
                        indegree[curr[j]-'a']++;
                    break;
                }
            }
        }
        
        // indegree topsort bfs;
        queue<int> q;
        for(auto ch: ust){
            if(indegree[ch-'a']==0){
                q.push(ch-'a');
                indegree[ch-'a']--;
            }
        }
        
        string res = "";
        while(!q.empty()){
            auto curr =q.front();q.pop();
            res += (curr+'a');
            for(auto v: graph[curr]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    indegree[v]--;
                }
            }
        }
        if(res.size()==ust.size())//check is size of res = total number of charachters
            return res;
        return "";
    }
};