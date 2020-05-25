#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    unordered_map<char,int> ump;
    for(auto& ch: s2){
        if(ch!=' ')
            ump[ch]++;
    }
    for(auto& ch: s1){
        if(ch!=' ' && ump.count(ch)){
            ump[ch]--;
            if(ump[ch]==0){
                ump.erase(ch);
            }
        }
    }
    string res = (ump.size()==0)?"YES\n":"NO\n";
    cout<<res;
    return 0;
}