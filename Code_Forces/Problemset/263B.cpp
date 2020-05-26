#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    long long int n,k;
    cin>>n>>k;
    vector<long long int> arr(26,0);
    for(int i=0; i<n; i++){
        char tmp;
        cin>>tmp;
        arr[tmp-'A']++;
    }
    sort(arr.begin(),arr.end());
    long long int res = 0;
    for(int i = 25; i>=0; i--){
        if(k==0){
            cout<<res<<"\n";
            return 0;
        }
        if(k>arr[i]){
            res += arr[i]*arr[i];
            k -= arr[i];
            arr[i] = 0;
        }
        else{
            res += k*k;
            arr[i]-=k;
            k = 0;
        }
    }
    cout<<res<<"\n";
    return 0;
}