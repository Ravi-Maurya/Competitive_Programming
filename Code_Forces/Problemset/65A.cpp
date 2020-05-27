#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        int k = s.size();
        if(k>10){
            char first = s[0];
            char last = s[k-1];
            s = first + to_string(k-2) + last;
        }
        cout<<s<<"\n";
    }
    return 0;
}