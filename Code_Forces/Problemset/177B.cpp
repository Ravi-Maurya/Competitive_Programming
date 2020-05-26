#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n,m,d;
    cin>>n>>m>>d;
    unordered_set<int> ust;
    vector<int> val;
    for(int i =0; i<n; i++){
        for(int j=0; j<m; j++){
            int tmp;
            cin>>tmp;
            ust.insert(tmp%d);
            val.push_back(tmp);
        }
    }
    if(ust.size()>1){
        cout<<-1<<"\n";
        return 0;
    }
    sort(val.begin(),val.end());
    n = val.size();
    int median = val[(n)/2];
    int res = 0;
    for(int i=0; i<n; i++){
        res += abs(median - val[i])/d;
    }
    cout<<res<<"\n";
    return 0;
}