#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n,x;
    cin>>n>>x;
    int sum = 0;
    for(int i=0;i<n; i++){
        int t;
        cin>>t;
        sum += t;
    }
    int res = 0;
    while(sum!=0){
        res++;
        int t = min(abs(sum),x);
        if(sum>0)
            sum -= t;
        else{
            sum += t;
        }
    }
    cout<<res<<"\n";
    return 0;
}