// https://zhuhan0.blogspot.com/2017/06/leetcode-269-alien-dictionary.html
// https://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
class Graph{
    int V;
    list<int> *adjList;
    Graph(int V){
        this->V = V;
        adjList = new list<int>[V];
    };
    void add_edge(int u, int v){
        adjList[u].push_back(v);
    }
    void helper(int ,v bool visited[], stack<int>& Stack){
        visited[v] = true;
        for(auto it = adjList[v].begin(); it!= adjList[v].end(); it++)
            if(!visited[*it])
                helper(*it, visited, Stack);
        Stack.push(v);
    }
    void topsort(){
        stack<int> Stack;
        bool *visited = new bool[V];
        for(int i=0; i<V; i++)
            visited[i] = false;
        for(int i=0; i<V;i++)
            if(!visited[i])
                helper(i,visited,Stack);
        while(!Stack.empty()){
            cout<<(char)('a' + Stack.top())<<" ";
            Stack.pop();
        }
    }
}


string solve(vector<string>& alien){
    int n = alien.size();
    unordered_set<char> ust;
    for(auto& s: alien){
        for(auto& ch: s){
            ust.insert(ch);
        }
    }
    int V = ust.size();
    Graph g(V);
    for(int i=0; i<n-1; i++){
        auto word1 = alien[i], word2 = alien[i+1];
        for(int j=0; j<min(word1.size(), word2.size()); j++){
            if(word1[j]!=word[j]){
                g.add_edge(word1[j]-'a', word2[j]-'a');
                break;
            }
        }
    }
    g.topsort();
}