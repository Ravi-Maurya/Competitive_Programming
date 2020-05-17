#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

// bool dfs(vector<vector<char>>& board, int r, int c, char ch, int i, int j, unordered_set<char>& visited, string& res){
//     if(i>=r || j>=c || i<0 || j<0)
//         return true;
    
    
// }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int r,c;
        cin>>r>>c;
        vector<vector<char>> board(r,vector<char>(c));
        unordered_set<char> charachters;
        unordered_set<char> visited;
        for(int i =0; i<r; i++)
            for(int j=0; j<c; j++){
                cin>>board[i][j];
                charachters.insert(board[i][j]);
            }
        string res = "";
        while(true){
            int size = visited.size();
            for(auto ch:charachters){
                bool flag = false;
                if(!visited.count(ch)){
                    flag = true;
                    bool ok = true;
                    for(int i=0; i<r;i++){
                        for(int j=0; j<c; j++){
                            if(!(board[i][j]==ch && (i+1<r)?(board[i+1][j]==ch || visited.count(board[i+1][j])):true)){
                                ok = false;
                                break;
                            }
                        }
                        if(!ok)
                            break;
                    }
                    if(ok)
                        visited.insert(ch);
                }
                if(visited.count(ch) && flag)
                    res += ch;
            }
            if(visited.size()==charachters.size())
                break;
            if(size-visited.size()==0){
                res = "";
                break;
            }
        }
        // string res = "";
        // for(int i=r-1; i>=0; i--){
        //     int curr_size = visited.size();
        //     bool flag = false;
        //     for(int j=0; j<c; j++){
        //         char ch = board[i][j];
        //         if(!visited.count(ch)){
        //             flag = true;
        //             dfs();
        //         }
        //     }
        //     if(visited.size()-curr_size==0 && flag){
        //         res = "";
        //         break;
        //     }

        // }
        cout<<"Case #"<<test<<": ";
        int a = -1;
        if(res.size()==0)
            cout<<a;
        else
            cout<<res;
        cout<<"\n";
    }
    return 0;
}