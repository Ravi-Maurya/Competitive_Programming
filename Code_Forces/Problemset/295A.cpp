#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n<26){
        cout<<"NO\n";
        return 0;
    }
    unordered_set<char> visit;
    for(auto ch: s){
        if(islower(ch))
            visit.insert(ch);
        else{
            ch = ch + 32;
            visit.insert(ch);
        }
    }
    cout<<((visit.size()==26)?"YES\n":"NO\n");
    return 0;
}