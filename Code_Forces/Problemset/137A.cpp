#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    k--;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=k+1;i<n;i++){
        if(arr[i]!=arr[i-1]){
            cout<<-1<<"\n";
            return 0;
        }
    }
    int res = 0;
    for(int i=k-1; i>=0; i--){
        if(arr[i]!=arr[k]){
            cout<<i+1<<"\n";
            return 0;
        }
    }
    cout<<0<<"\n";
    return 0;
}