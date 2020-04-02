int Solution::solve(const vector<int> &A) {
    int n = A.size();
    if(n<=1)
        return 1;
    int res = 1;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
            int curr = 2;
            int prev = A[j];
            int diff = A[j]-A[i];
            for(int k=j+1;k<n;k++)
                if(A[k]==prev+diff){
                    curr++;
                    prev = A[k];
                }
            res = max(res,curr);
        }
    return res;
}
