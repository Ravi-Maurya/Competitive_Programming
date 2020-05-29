#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin>>s;
    if(s.size()){
        if(islower(s[0]))
            s[0] = s[0] - 32;
    }
    cout<<s<<"\n";
    return 0;
}