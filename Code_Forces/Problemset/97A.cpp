#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=1; i<=n ;i++){
        int t;
        cin>>t;
        arr[t] = i;
    }
    for(int i=1;i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}