#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.size();
    for(int i=0; i<n; i++){
        int ch1 = (tolower(s1[i]) - 'a'), ch2 = (tolower(s2[i]) - 'a');
        // cout<<ch1<<" "<<ch2<<"\n";
        if(ch1>ch2){
            cout<<"1\n";
            return 0;
        }
        else if(ch1<ch2){
            cout<<"-1\n";
            return 0;
        }
    }
    cout<<"0\n";
    return 0;
}