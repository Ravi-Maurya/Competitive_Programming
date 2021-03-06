#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")
const long long int mod = 1000000007;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        long long int sum = 0;
        sort(arr.rbegin(),arr.rend());
        for(int i=0;i<n;i++){
            long long int tmp = (arr[i] - i);
            if (tmp<0)
                tmp = 0;
            sum = (sum%mod + tmp%mod)%mod;
        }
        cout<<sum%mod<<endl;
    }
    return 0;
}