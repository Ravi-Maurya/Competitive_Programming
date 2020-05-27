#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    string s1,s2,Xor="";
    cin>>s1>>s2;
    int n = s1.size();
    for(int i=0; i<n; i++){
        auto ch1 = s1[i], ch2 = s2[i];
        if(ch1==ch2){
            Xor += '0';
        }
        else{
            Xor += '1';
        }
    }
    cout<<Xor<<"\n";
    return 0;
}