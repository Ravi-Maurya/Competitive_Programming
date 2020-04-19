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
        long long int d;
        cin>>n>>d;
        vector<long long> arr(n),mul(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mul[i] = d/arr[i];
        }
        for(int i=1;i<n;i++){
            if(arr[i]*mul[i]<arr[i-1]*mul[i-1]){
                for(int j=i-1;j>=0;j--){
                    mul[j] = (arr[j+1]*mul[j+1])/arr[j];
                }
            }
        }
        cout<<"Case #"<<test<<": "<<arr[0]*mul[0]<<"\n";
    }
    return 0;
}