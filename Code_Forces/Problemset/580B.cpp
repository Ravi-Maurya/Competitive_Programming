#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

typedef long long int ll;

void dfs(int idx, int curr,vector<bool>& visited, vector<int>& order, vector<ll>& arr, int& res){
    visited[idx] = 1;
    order[idx] = curr;
    for(int i=0;i<arr.size(); i++)
        if((arr[i] & arr[idx]) !=0){
            if(!visited[i] || order[i]>curr+1)
                dfs(i,curr+1,visited,order,arr,res);
            else if(order[idx]-order[i]+1>=3)
                if(res==-1 || res>order[idx] - order[i]+1)
                    res = order[idx] - order[i]+1;
        }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<ll> arr;
    vector<int> bit_count(101,0);
    for(int i=0; i<n; i++){
        ll tmp;
        cin>>tmp;
        if(tmp!=0)
            arr.push_back(tmp);
    }
    n = arr.size();
    for(int i=0; i<n; i++){
        ll val = arr[i];
        for(int idx = 0; val>0; idx++){
            if(val&1)
                bit_count[idx]++;
            val >>= 1;
        }
    }
    for(int i=0;i<101; i++)
        if(bit_count[i]>=3){
            cout<<3<<"\n";
            return 0;
        }
    int res = -1;
    vector<int> order(n,-1);
    vector<bool> visited(n,false);
    for(int i=0; i<n; i++)
        if(!visited[i])
            dfs(i,1,visited,order,arr,res);
    cout<<res<<"\n";
    return 0;
}