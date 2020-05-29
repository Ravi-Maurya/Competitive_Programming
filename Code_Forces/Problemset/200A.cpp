#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    int res = 0;
    string prev = "";
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(i==0 || (prev[0] != s[0])){
            res++;
        }
        prev = s;
    }
    cout<<res<<"\n";
    return 0;
}