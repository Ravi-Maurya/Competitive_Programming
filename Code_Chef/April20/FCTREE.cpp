#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
#define mod 1000000007

void primeFactors(int n, unordered_map<int,long long int>& dic){
    while(n%2 == 0){
        if(dic.find(2)==dic.end())
            dic[2] = 1;
        else
            dic[2] += 1;
        n = n/2;
    }
    for(int i=3; i<= (int)(sqrt(n)); i+=2){
        while(n%i == 0){
            if(dic.find(i)==dic.end())
                dic[i] = 1;
            else
                dic[i] += 1;
            n = n/i;
        }
    }
    if(n>2){
        if(dic.find(n)==dic.end())
            dic[n] = 1;
        else
            dic[n] += 1;
    }
    return;
}

void calculate(vector<int> path, vector<int>& sequence){
    unordered_map<int,long long int> dic;
    for(int i=0;i<path.size();i++)
        primeFactors(sequence[path[i]-1],dic);
    long long int res = 1;
    for(auto it=dic.begin() ; it!=dic.end(); it++){
        res *= (1 + it->second);
        res %= mod;
    }
    cout<<res<<"\n";
}

void bfs(vector<bool>& visited, int x, int y, queue<int>& q, vector<vector<int>>& edges, bool& ans, vector<int>& sequence){
    q.push(x);
    visited[x] = 1;
    vector<int> res;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        res.push_back(x);
        if(u==y){
            ans = 1;
            calculate(res, sequence);
        }
        for(auto v:edges[u]){
            if(!visited[v]){
                q.push(v);
                visited[v] = 1;
            }
        }
    }
    return;
}

void dfs(vector<bool>& visited, int x, int y, vector<int>& Stack, vector<vector<int>>& edges, bool& ans, vector<int>& sequence){
    Stack.emplace_back(x);
    if(x==y){
        ans = 1;
        calculate(Stack,sequence);
        return;
    }
    visited[x] = 1;
    bool flag = 0;
    if(edges[x].size()>0){
        for(auto j:edges[x]){
            if(!visited[j]){
                dfs(visited,j,y,Stack,edges,ans,sequence);
                if(ans){
                    flag = 1;
                    break;
                }
            }
        }
    }
    if(!flag)
        Stack.pop_back();
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n;
        vector<vector<int>> edges(n+1);
        vector<int> sequence(n);
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        for(int i=0;i<n;i++)
            cin>>sequence[i];
        cin>>q;
        for(int i=0;i<q;i++){
            int x,y;
            cin>>x>>y;
            queue<int> tmp;
            bool ans = 0;
            vector<bool> visited(n+1,0);
            if(x!=y)
                bfs(visited, x, y, tmp, edges, ans, sequence);
            else
                calculate({x},sequence);
        }
    }
}