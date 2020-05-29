#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    unordered_set<char> visited;
    string s1;
    getline(cin,s1);
    for(auto ch:s1){
        if(isalpha(ch)){
            visited.insert(ch);
        }
    }
    int res = visited.size();
    cout<<res<<"\n";
    return 0;
}