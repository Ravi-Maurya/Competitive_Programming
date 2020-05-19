#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<long long int> arr(n),res(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++)
        res[i] = (i==0?0:res[i-1]) + arr[i] - (i-m<0?0:arr[i-m]);
    for(int i=1; i<n; i++)
        arr[i]+=arr[i-1];
    for(int i=m;i<n;i++)
        res[i] = res[i] + res[i-m] + arr[i-m];
    for(int i=0; i<n; i++){
        cout<<res[i]<<" ";
    }
    cout<<"\n";
    return 0;
}