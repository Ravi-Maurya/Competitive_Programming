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
        for(int i=0; i<n;i++)
            cin>>arr[i];
        int count = 0;
        for(int i=1;i<n-1;i++)
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
                count++;
        cout<<"Case #"<<test<<": "<<count<<"\n";
    }
    return 0;
}