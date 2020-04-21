#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("-O3")

vector<vector<int> > generateMatrix(int A) {
    vector<vector<int>> grid(A,vector<int>(A,0));
    if (A==0)
        return grid;
    int top = 0, bottom = A-1, left = 0, right = A-1;
    int direction = 1;
    int element = 1;
    while (top<=bottom && left<=right){
        if (direction==1){
            for(int i=left;i<=right;i++){
                grid[top][i] = element;
                element++;
            }
            top++;
            direction = 2;
        }
        else if(direction==2){
            for(int i=top;i<=bottom;i++){
                grid[i][right] = element;
                element++;
            }
            right--;
            direction = 3;
        }
        else if(direction==3){
            for(int i=right;i>=left;i--){
                grid[bottom][i] = element;
                element++;
            }
            bottom--;
            direction = 4;
        }
        else{
            for(int i=bottom;i>=top;i--){
                grid[i][left] = element;
                element++;
            }
            left++;
            direction = 1;
        }
    }
    return grid;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    return 0;
}