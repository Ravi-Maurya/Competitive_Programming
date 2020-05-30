#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    int res = 0;
    for(int i=0;i<m;i++){
        if(arr[i]<=0)
            res += abs(arr[i]);
        else
            break;
    }
    cout<<res<<"\n";
    return 0;
}