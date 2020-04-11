#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        long long int res = 0;
        cin>>n;
        vector<long long int> arr(n);
        for(int i=0; i<n; i++)
            cin>>arr[i];
        for(int i=0;i<n;i++){
            unsigned long long int curr = 1;
            for(int j=i; j<n; j++){
                curr *= abs(arr[j]);
                if(curr%4 != 2)
                    res += 1;
            }
        }
        cout<<res<<endl;
    }

    return 0;
}