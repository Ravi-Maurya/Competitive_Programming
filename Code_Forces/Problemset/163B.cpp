#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

void solve(string& s){
    int n = s.size();
    int i = 0;
    bool no_swap = true;;
    while(i<n-1){
        if(s[i]=='B' && s[i+1]=='G'){
            s[i] = 'G';
            s[i+1] = 'B';
            i += 2;
            no_swap = false;
        }
        else{
            i += 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n,t;
    cin>>n>>t;
    string s;
    cin>>s;
    while(t--){
        solve(s);
    }
    cout<<s<<"\n";
    return 0;
}