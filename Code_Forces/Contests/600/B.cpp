#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n);
    long long int sum = 0;
    unordered_map<int,bool> ump;
    bool valid = true;
    set<int> idx;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
        if(arr[i]<0){
            if(ump.count(-1*arr[i]) && !ump[-1*arr[i]])
                ump[-1*arr[i]] = true;
            else
                valid = false;
        }
        else{
            if(ump.count(arr[i]))
                valid = false;
            else
                ump[arr[i]] = false;
        }
        if(valid && sum==0){
            idx.insert(i);
            ump.clear();
        }
    }
    if(!(valid && sum==0))
        cout<<-1<<"\n";
    else{
        int tmp = 0;
        cout<<idx.size()<<"\n";
        for(auto it = idx.begin(); it!=idx.end();it++){
            // cout<<*it<<" "<<tmp<<"\n";
            cout<<(*it + 1 - tmp)<<" ";
            tmp += (*it + 1 - tmp);
        }
        cout<<"\n";
    }
    return 0;
}