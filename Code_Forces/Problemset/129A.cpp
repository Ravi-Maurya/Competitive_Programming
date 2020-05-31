#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    priority_queue<pair<int,int>, vector<pair<int,int>>,  greater<pair<int,int>>> pq;
    ll n;
    cin>>n;
    for(int i=1;i<=n; i++){
        ll time;
        cin>>time;
        pq.push({time,i});
    }
    auto curr = pq.top();pq.pop();
    if(!pq.empty() && pq.top().first == curr.first){
        cout<<"Still Rozdil\n";
        return 0;
    }
    cout<<curr.second<<"\n";
    return 0;
}