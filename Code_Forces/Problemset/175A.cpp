#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    int straight = n - k - 1;
    for(int i=1;i<=straight;i++)
        cout<<i<<" ";
    for(int i=n; i>straight;i--)
        cout<<i<<" ";
    cout<<"\n";
    return 0;
}