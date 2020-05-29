#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    string s1,s2,s;
    cin>>s1>>s2>>s;
    vector<int> arr(26,0);
    if((s1.size() + s2.size())==s.size()){
        for(auto& ch:s1){
            arr[ch-'A']++;
        }
        for(auto& ch:s2){
            arr[ch-'A']++;
        }
        for(auto& ch:s){
            arr[ch-'A']--;
        }
        for(int i=0; i<26; i++){
            if(arr[i]!=0){
                cout<<"NO\n";
                return 0;
            }
        }
        cout<<"YES\n";
        return 0;
    }
    cout<<"NO\n";
    return 0;
}