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
        vector<long int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        long int curr_max = arr[0], global_max = arr[0];
        for(int i=1;i<n;i++){
            curr_max = max(arr[i], arr[i]+curr_max);
            global_max = max(curr_max, global_max);
        }
        cout<<global_max<<"\n";
    }
    return 0;
}