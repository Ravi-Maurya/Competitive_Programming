#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

const int mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int x,y;
    cin>>x>>y;
    int n;
    cin>>n;
    vector<int> arr(6);
    arr[1] = (x<0)?x+mod:x;
    arr[2] = (y<0)?y+mod:y;
    long long int tmp;
    for(int i=3; i<=6; i++){
        tmp = y-x;
        // cout<<tmp<<"\n";
        while(tmp<0)
            tmp += mod;
        while(tmp>mod)
            tmp -= mod;
        arr[i%6] = tmp;
        x = y;
        y = tmp;
    }
    cout<<arr[n%6]<<"\n";
    return 0;
}