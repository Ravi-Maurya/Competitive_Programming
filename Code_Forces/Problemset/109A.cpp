#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    int res = 0;
    int maxval = INT_MIN, minval = INT_MAX;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        if(a>maxval || a<minval){
            res++;
            maxval = max(maxval,a);
            minval = min(minval,a);
        }
    }
    cout<<res-1<<"\n";
    return 0;
}