#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    int max_capacity = 0;
    int total = 0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        total += (b-a);
        max_capacity = max(max_capacity,total);
    }
    cout<<max_capacity<<"\n";
    return 0;
}