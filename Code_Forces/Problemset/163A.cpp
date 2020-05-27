#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    string s;
    cin>>n>>s;
    int i = 0;
    int res = 0;
    while(i<n){
        int count = 0;
        while(i<n-1 && s[i]==s[i+1]){
            i++;
            count++;
        }
        i++;
        res += count;
    }
    cout<<res<<"\n";
    return 0;
}