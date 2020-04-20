#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

vector<int> toSol(vector<vector<int>> &board, int n){
    vector<int> tmp(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==1){
                tmp[i] = j+1;
                break;
            }
        }
    }
    return tmp;
}

bool isSafe(vector<vector<int>> &board, int row, int col, int n){
    for(int j=0;j<col;j++)
        if (board[row][j]!=0)
            return false;
    int i=row;
    int j = col;
    while (i>=0 && j>=0){
        if (board[i][j]!=0)
            return false;
        i--;
        j--;
    }
    i = row;
    j = col;
    while (i<n && j>=0){
        if(board[i][j]!=0)
            return false;
        i++;
        j--;
    }
    return true;
}

bool solveQ(vector<vector<int>> &res, vector<vector<int>> &board, int col, int n){
    if (col==n){
        vector<int> tmp = toSol(board,n);
        res.push_back(tmp);
        return true;
    }
    bool r = false;
    for(int i=0;i<n;i++){
        if (isSafe(board,i,col,n)){
            board[i][col] = 1;
            r = (solveQ(res,board,col+1,n) || r);
            board[i][col] = 0;
        }
    }
    return r;
}

void solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int>> board(A,vector<int>(A,0));
    vector<vector<int>> res;
    bool exist = solveQ(res,board,0,A);
    if(!exist){
        cout<<-1<<"\n";
        return;
    }
    sort(res.begin(),res.end());
    for(int i =0; i<res.size();i++){
        printf("[");
        for(auto x: res[i]){
            printf("%d ",x);
        }
        printf("] ");
    }
    printf("\n");
    return;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    for(int test = 1; test <= t; test++){
        int n;
        cin>>n;
        if(n==2 || n==3){
            printf("%d\n",-1);
        }
        else{solveNQueens(n);}
    }
    return 0;
}