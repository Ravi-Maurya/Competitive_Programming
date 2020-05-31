#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    for(int i = 0 ; i<n; i++){
        if(arr[i]!=(i+1)){
            cout<<(i+1)<<"\n";
            return 0;
        }
    }
    cout<<(n+1)<<"\n";
    return 0;
}