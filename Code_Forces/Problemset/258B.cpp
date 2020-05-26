#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(auto i=0; i<n; i++)
        cin>>arr[i];
    ll i,j;
    ll left = -1, right = -1;
    for(i=0; i<n-1; i++){
        if(arr[i]>arr[i+1]){
            left = i;
            break;
        }
    }
    if(left==-1){
        cout<<"yes\n";
        cout<<1<<" "<<1<<"\n";
        return 0;
    }
    for(j=n-1; j>left; j--){
        if(arr[j-1]>arr[j]){
            right = j;
            break;
        }
    }
    if((left>0 && arr[left-1]>arr[right]) || (right<n-1 && arr[left]>arr[right+1])){
        cout<<"no\n";
        return 0;
    }
    for(i=left;i<right;i++){
        if(arr[i]<arr[i+1]){
            cout<<"no\n";
            return 0;
        }
    }
    cout<<"yes\n";
    cout<<left+1<<" "<<right+1<<"\n";
    return 0;
}