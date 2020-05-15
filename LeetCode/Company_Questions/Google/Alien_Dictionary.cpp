#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
// There is a new alien language which uses the latin alphabet. 
//However, the order among letters are unknown to you.
//You receive a list of non-empty words from the dictionary, 
//where words are sorted lexicographically by the rules of this new language.
//Derive the order of letters in this language.
// Example 1:
// Given the following words in dictionary,
// [
//   "wrt",
//   "wrf",
//   "er",
//   "ett",
//   "rftt"
// ]
// The correct order is: "wertf".

string alien(vector<string>& dictionary){
    int n = dictionary.size();
    vector<int> indegree(26,0);
    unordered_map<char,unordered_set<char>> graph;
    // Build Graph
    for(int i = 1; i<n; i++){
        auto first = dictionary[i-1];
        auto second = dictionary[i];
        int l = min(first.size(),second.size());
        for(int j=0; j<l; j++){
            auto u = first[j];
            auto v = second[j];
            if(u!=v){
                if(!(graph.count(u) && graph[u].count(v))){
                    graph[u].insert(v);
                    indegree[v-'a']++;
                }
                break;
            }
        }
    }
    // Topological Sorting
    queue<char> q;
    for(auto it = graph.begin(); it!=graph.end(); it++){
        if(indegree[it->first-'a']==0)
            q.push(it->first);
    }
    string res = "";
    while(!q.empty()){
        auto u = q.front(); q.pop();
        res.push_back(u);
        for(auto it = graph[u].begin(); it!=graph[u].end(); it++){
            auto v = *it;
            indegree[v]--;
            if(indegree[v]==0)
                q.push(v);
        }
    }
    return res.size()==graph.size()?res:"";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}