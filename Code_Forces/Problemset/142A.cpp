#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int s,n;
    cin>>s>>n;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        pq.push({x,y});
    }
    while(!pq.empty()){
        if(s> pq.top().first){
            s += pq.top().second;
            pq.pop();
        }
        else
            break;
    }
    if(pq.empty())
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}