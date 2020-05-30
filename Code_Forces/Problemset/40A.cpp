#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    string s1,s2;
    cin>>s1>>s2;
    if(s1.size() != s2.size()){
        cout<<"NO\n";
        return 0;
    }
    int i = 0, n = s1.size();
    while(i<n){
        if(s1[i]!=s2[n-1-i]){
            cout<<"NO\n";
            return 0;
        }
        i++;
    }
    cout<<"YES\n";
    return 0;
}