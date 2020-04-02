vector<int> row = {0,-1,-1,-1,0,1,1,1};
vector<int> col = {1,1,0,-1,-1,-1,0,1};

void rec(vector<string> &A, vector<vector<int>> &res, int i, int j, int k, int n, int m){
    if(i<0 || j<0 || i>=n || j>=m)
        return;
    if(A[i][j]=='1'){
        res[i][j]++;
        return;
    }
    res[i][j]++;
    rec(A,res,i+row[k],j+col[k],k,n,m);
    return;
}

vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> res(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<8;k++)
                if(A[i][j]=='1')
                    rec(A,res,i+row[k],j+col[k],k,n,m);
    return res;
}
