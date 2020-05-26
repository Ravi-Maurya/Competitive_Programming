#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)
        cin>>a[i]>>b[i];
    int res = n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[i]==b[j] && i!=j){
                res--;
                break;
            }
    cout<<res<<"\n";
    return 0;
}