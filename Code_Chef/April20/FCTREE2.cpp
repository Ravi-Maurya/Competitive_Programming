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
int isNotVisited(int x, vector<int>& path){ 
    int size = path.size(); 
    for (int i = 0; i < size; i++)  
        if (path[i] == x)  
            return 0;  
    return 1; 
} 

void bfs(int x, int y, vector<vector<int>>& edges, vector<int>& sequence){
    queue<vector<int>> q;
    vector<int> res;
    res.push_back(x);
    q.push(res);
    while (!q.empty()){
        vector<int> path = q.front();
        q.pop();
        int lastu = path[path.size()-1];
        if (lastu == y){
            calculate(path,sequence);
            return;
        }
        for(auto v:edges[lastu]){
            if(isNotVisited(v,path)){
                vector<int> nwpath(path);
                nwpath.push_back(v);
                if(v==y){
                    calculate(nwpath,sequence);
                    return;
                }
                q.push(nwpath);
            }
        }
    }
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
            if(x!=y)
                bfs(x, y, edges, sequence);
            else
                calculate({x},sequence);
        }
    }
}