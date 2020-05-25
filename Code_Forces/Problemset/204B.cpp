#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int check(set<int>& st){
    int diff = 0;
    for(auto it = st.begin(); it!=st.end(); it++){
        if(it==st.begin())
            continue;
        auto prev = it;
        --prev;
        int tmp = (*it) - (*prev);
        // cout<<diff<<" "<<tmp<<"\n";
        if(prev==st.begin()){
            diff = tmp;
            continue;
        }
        if(tmp != diff)
            return -1;
    }
    return diff;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    map<int,set<int>> mp;
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        mp[tmp].insert(i);
    }
    vector<pair<int,int>> res;
    for(auto& [val,st]: mp){
        if(st.size()==1)
            res.push_back({val,0});
        else{
            int d = check(st);
            if(d!=-1){
                res.push_back({val,d});
            }
        }
    }
    cout<<res.size()<<"\n";
    for(auto& p: res)
        cout<<p.first<<" "<<p.second<<"\n";
    return 0;
}