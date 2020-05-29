#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    vector<string> res(n);
    for(int i=0; i<(n+1)/2; i++){
        string tmp = "";
        int d = 2*i + 1;
        int sides = (n - d)/2;
        for(int k=0;k<sides;k++)
            tmp += '*';
        for(int k=0;k<d;k++)
            tmp += 'D';
        for(int k=0;k<sides;k++)
            tmp += '*';
        res[i] = res[n-i-1] = tmp;
    }
    for(int i=0;i<n; i++)
        cout<<res[i]<<"\n";
    return 0;
}