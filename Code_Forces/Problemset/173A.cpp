#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int res = 0;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        if(s[0]=='+' || s[2]=='+')
            res++;
        else
            res--;
    }
    cout<<res<<"\n";
    return 0;
}