int n,m,ns;
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};
 
bool dfs(int x, int y, vector<string> &A, string B, int ind){
    if(ind == ns)
        return true;
 
    for(int i=0;i<4;i++){
        int newx = x+X[i];
        int newy = y+Y[i];
        if(newx>=0 && newx<n && newy>=0 && newy<m && A[newx][newy]==B[ind]){
            if(dfs(newx,newy,A,B,ind+1))
                return true;
        }
    }
    return false;
}

int Solution::exist(vector<string> &A, string B) {
    n = A.size();
    m = A[0].size();
    ns = B.length();
    if(ns == 0)
        return 1;
    bool ans = false;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(A[i][j] == B[0]){
                ans |= dfs(i,j,A,B,1);
                if(ans)
                    return 1;
            }
    return 0;
}
