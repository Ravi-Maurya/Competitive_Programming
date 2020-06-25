class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        int res = INT_MAX;
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                int tmp = A[i+1][j];
                if(j>0)
                    tmp = min(tmp,A[i+1][j-1]);
                if(j<n-1)
                    tmp = min(tmp,A[i+1][j+1]);
                A[i][j] += tmp;
            }
        }
        for(auto x: A[0])
            res = min(x,res);
        return res;
    }
};