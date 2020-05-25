#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int count_odd(string& s){
    int odd = 0;
    vector<int> alp(26,0);
    for(auto& ch:s)
        alp[ch-'a']++;
    for(int i=0; i<26; i++)
        if(alp[i]>0 && alp[i]&1)
            odd++;
    return odd;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin>>s;
    int times = count_odd(s);
    if(times<=1 || times&1)
        cout<<"First\n";
    else
        cout<<"Second\n";
    return 0;
}