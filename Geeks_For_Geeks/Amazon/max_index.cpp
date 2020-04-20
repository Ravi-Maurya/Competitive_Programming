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
        vector<long long int> arr(n),left(n),right(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        for(int i=1; i<n; i++){
            left[i] = min(arr[i],left[i-1]);
            right[n-i-1] = max(arr[n-i-1],right[n-i]);
        }
        int res = 0,i=0,j=0;
        while (j<n && i<n){
            if(left[i]<=right[j]){
                res = max(res,j-i);
                j++;
            }
            else
                i++;
        }
        cout<<res<<"\n";
    }
    return 0;
}