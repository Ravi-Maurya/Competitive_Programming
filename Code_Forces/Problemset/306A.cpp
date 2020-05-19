#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin>>s;
    auto found = s.find("AB");
    bool ab = false;
    if(found!=s.npos){
        string s2 = s.substr(found+2);
        auto found2 = s2.find("BA");
        if(found2!=s2.npos){
            ab = true;
        }
    }
    if(ab){
        cout<<"YES\n";
        return 0;
    }
    ab = false;
    found = s.find("BA");
    if(found!=s.npos){
        string s2 = s.substr(found+2);
        auto found2 = s2.find("AB");
        if(found2!=s2.npos)
            ab = true;
            
    }
    if(ab){
        cout<<"YES\n";
        return 0;
    }
    cout<<"NO\n";
    return 0;
}