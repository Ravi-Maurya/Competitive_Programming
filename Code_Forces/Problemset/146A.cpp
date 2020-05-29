#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    unordered_set<char> count;
    string s;
    cin>>s;
    for(auto& ch:s)
        count.insert(ch);
    if((count.size())&1)
        cout<<"IGNORE HIM!\n";
    else
        cout<<"CHAT WITH HER!\n";
    return 0;
}