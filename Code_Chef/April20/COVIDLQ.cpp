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
        int boundary = 6;
        int n;
        cin>>n;
        vector<int> arr(n);
        string res = "YES";
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=0;i<n;i++){
            int tmp = arr[i];
            if(tmp==1 && boundary>=6)
                boundary = 1;
            else if(tmp==1 && boundary<6){
                res = "NO";
                break;
            }
            else if(tmp==0)
                boundary += 1;
        }
        cout<<res<<endl;
    }
    return 0;
}