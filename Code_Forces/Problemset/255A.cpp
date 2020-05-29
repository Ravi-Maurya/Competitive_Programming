#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<string> arr(2);
    string tmp1 = "", tmp2 = "";
    for(int i=1;i<=n; i++){
        if(i&1){
            tmp1 += 'C';
            tmp2 += '.';
        }
        else{
            tmp1 += '.';
            tmp2 += 'C';
        }
    }
    arr[0] = tmp1;
    arr[1] = tmp2;
    int res = n*(floor(n/2));
    if(n&1)
        res += (n+1)/2;
    cout<<res<<"\n";
    for(int i=0;i<n;i++){
        cout<<arr[i%2]<<"\n";
    }
    return 0;
}