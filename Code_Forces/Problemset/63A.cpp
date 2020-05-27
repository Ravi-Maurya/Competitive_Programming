#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int x =0, y =0, z = 0;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int xi,yi,zi;
        cin>>xi>>yi>>zi;
        x += xi;
        y += yi;
        z += zi;
    }
    cout<<((x==0 && y==0 && z==0)?"YES\n":"NO\n");
    return 0;
}