#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test<=t; test++){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++)
            cin>>a[i];
        unordered_map<int,vector<int>> idx_mapp;
        for(int i=0; i<n; i++){
            int tmp;
            cin>>tmp;
            a[i] = tmp-a[i];
            idx_mapp[a[i]].push_back(i);
        }
        string res = "YES";
        if(idx_mapp.size()>2)
            res = "NO";
        else{
            if(idx_mapp.size()==1){
                auto it = idx_mapp.begin();
                if(it->first < 0)
                    res = "NO";
            }
            else{
                bool flag = false,continuous = true;
                for(auto it =  idx_mapp.begin(); it!=idx_mapp.end(); it++){
                    if(it->first<0){
                        continuous = false;
                        break;
                    }
                    if(it->first == 0){
                        flag = true;
                    }
                    else{
                        for(int i=1; i<it->second.size(); i++){
                            if(it->second[i]!=it->second[i-1]+1){
                                continuous = false;
                                break;
                            }
                        }
                    }
                }
                if(!(flag && continuous))
                    res = "NO";
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}