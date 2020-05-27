#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    unordered_set<int> row,col;
    int r,c;
    cin>>r>>c;
    for(int i=0; i<r; i++){
        string s;
        cin>>s;
        for(int j=0;j<c;j++){
            if(s[j]=='S'){
                row.insert(i);
                col.insert(j);
            }
        }
    }
    int rem_row = r - row.size();
    int rem_col = c - col.size();
    int res = rem_col*r + rem_row*c - (rem_row*rem_col);
    cout<<res<<"\n";
    return 0;
}