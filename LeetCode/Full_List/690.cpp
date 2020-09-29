/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,pair<int,unordered_set<int>>> graph;
        for(int i=0; i<employees.size(); i++){
            graph[employees[i]->id].first = employees[i]->importance;
            for(int j=0; j<employees[i]->subordinates.size(); j++)
                graph[employees[i]->id].second.insert(employees[i]->subordinates[j]);
        }
        unordered_set<int> visited;
        queue<int> q;
        int res = 0;
        q.push(id);
        visited.insert(id);        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(graph.count(u))
                res += graph[u].first;
            for(auto& v: graph[u].second){
                if(!visited.count(v)){
                    q.push(v);
                    visited.insert(v);
                }
            }
        }
        return res;
    }
};