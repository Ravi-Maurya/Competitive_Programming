#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    int maxval = -1, minval = 102;
    int maxidx = -1, minidx = -1;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(arr[i]>maxval){
            maxval = arr[i];
            maxidx = i;
        }
        if(arr[i]<=minval){
            minval = arr[i];
            minidx = i;
        }
    }
    if(maxidx == 0 && minidx == n-1){
        cout<<"0\n";
        return 0;
    }
    int maxswap = maxidx;
    int minswap = n-1-minidx;
    int res = maxswap + minswap;
    if(maxidx>minidx)
        res -= 1;
    cout<<res<<"\n";
    return 0;
}