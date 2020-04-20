// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  

bool SolveSudoku(int grid[N][N]);

void printGrid(int grid[N][N]);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		
		if (SolveSudoku(grid) == true)  
            printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}// } Driver Code Ends
// bool SolveSudoku(int grid[N][N])

bool isSafe(int board[N][N], int row, int col, int num, int n){
    for(int j=0;j<n;j++)
        if (board[row][j]==num)
            return false;
    for(int i=0;i<n;i++)
        if(board[i][col]==num)
            return false;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if ((row-row%3 +i<n) && (col-col%3 +j<n) && board[row-row%3 +i][col-col%3 +j]==num)
                return false;
    return true;
}

bool solve(int board[N][N], int row, int col, int n){
    if(row==n){
        row=0;
        col++;
        if(col==n)
            return true;
    }
    if(board[row][col]!=0)
        return solve(board,row+1,col,n);
    for(int num = 1; num<=n;num++){
        if (isSafe(board,row,col,num,n)){
            board[row][col] = num;
            if (solve(board,row+1,col,n))
                return true;
            board[row][col] = 0;
        }
    }
    return false;
}

bool SolveSudoku(int grid[N][N])
{ 
    return solve(grid,0,0,N);
}

void printGrid (int grid[N][N]) 
{
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            printf("%d ",grid[i][j]);
    // printf("\n");
    return;
}
