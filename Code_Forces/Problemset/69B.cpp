#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n);
    bool repeats = false;
    priority_queue<pair<int,int>> pq;
    unordered_set<int> ust,visited;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(ust.count(arr[i]))
            repeats = true;
        ust.insert(arr[i]);
        pq.push({arr[i],i});
    }
    if(repeats){
        cout<<"NO"<<"\n";
        return 0;
    }
    ust.clear();
    auto largest = pq.top();pq.pop();
    ust.insert(largest.second + 1);
    ust.insert(largest.second - 1);
    while (!pq.empty()){
        auto curr = pq.top();pq.pop();
        if(!ust.count(curr.second)){
            cout<<"NO"<<"\n";
            return 0;
        }
        ust.insert(curr.second + 1);
        ust.insert(curr.second - 1);
    }
    cout<<"YES"<<"\n";
    return 0;
}