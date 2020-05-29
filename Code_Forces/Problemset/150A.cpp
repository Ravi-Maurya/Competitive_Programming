#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> res(k);
    unordered_set<int> visited;
    for(int i=0;i<k; i++){
        int ai;
        cin>>ai;
        res[i] = ai;
        visited.insert(ai);
    }
    vector<int> arr;
    for(int i=1;i<=n*k;i++){
        if(!visited.count(i))
            arr.push_back(i);
    }
    int tmp = 0;
    for(int i=0;i<k;i++){
        cout<<res[i]<<" ";
        int j = tmp+n-1;
        for(;tmp<j;tmp++)
            cout<<arr[tmp]<<" ";
        cout<<"\n";
    }
    return 0;
}