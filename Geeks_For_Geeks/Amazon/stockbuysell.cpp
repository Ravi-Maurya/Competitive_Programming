#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int i=0;
        int j=1;
        set<pair<int,int>> res;
        while(j<n){
            while(j<n && arr[j-1]<=arr[j])
                j++;
            if(i!=j-1){
                res.insert(make_pair(i,j-1));
            }
            i = j;
            j = i+1;
        }
        if(res.size()!=0){
            for(auto it = res.begin(); it!=res.end();it++)
                cout<<"(" <<it->first <<" " <<it->second <<") ";
            cout<<"\n";
        }
        else
            cout<<"No Profit\n";
    }
    return 0;
}