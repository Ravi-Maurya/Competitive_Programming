#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    string s;
    cin>>s;
    int l = 0, u = 0;
    for(auto& ch: s){
        if('A'<=ch && ch<='Z')
            u++;
        else
            l++;
    }
    if(l>=u){
        for(auto ch:s){
            if(!(ch>=97 && ch<=122))
                ch = ch+32;
            cout<<ch;
        }
    }    
    else{
        for(auto ch:s){
            if(ch>=97 && ch<=122)
                ch = ch-32;
            cout<<ch;
        }
    }
    cout<<"\n";
    return 0;
}