// Simple Sorting

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin>>T;
    for(int test =1; test<=T;test++){
        int n,b;
        cin>>n>>b;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr.begin(),arr.end());
        int res = 0;
        for(int i=0;i<n;i++){
            if (arr[i]<=b){
                b -= arr[i];
                res++;
            }
            else{
                break;
            }
        }
        cout<<"Case #"<<test<<": "<<res<<"\n";
    }
    return 0;
}