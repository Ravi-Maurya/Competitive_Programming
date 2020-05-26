#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    vector<string> board(8);
    unordered_set<int> black;
    bool found = false;
    int resw = -1, resb = 9;
    for(int i=0; i<8; i++){
        string tmp;
        cin>>tmp;
        board[i] = tmp;
        for(int j=0; j<8; j++){
            if(tmp[j]=='B')
                black.insert(j);
            else if(!found && tmp[j]=='W' && !black.count(j)){
                found = true;
                resw = i;
            }
        }
    }
    for(auto& j:black){
        for(int i=7;i>=0;i--){
            if(board[i][j]!='.'){
                if(board[i][j]=='B')
                    resb = min(resb,8-i-1);
                break;
            }
        }
    }
    // cout<<resw<<" "<<resb<<"\n";
    if(resw==-1)
        cout<<"B\n";
    else
        cout<<((resw<=resb)?"A":"B")<<"\n";
    
    return 0;
}