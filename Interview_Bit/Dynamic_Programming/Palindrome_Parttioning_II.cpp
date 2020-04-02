int Solution::minCut(string A) {
    int n = A.size(),i,j,k,l;
    bool Pal[n][n];
    int res[n];
    for(i=0;i<n;i++)
        Pal[i][i] = true;
    for(l=2;l<=n;l++){
        for(i=0;i<n-l+1;i++){
            j = i+l - 1;
            Pal[i][j] = A[i]==A[j];
            if(l>2)
                Pal[i][j] = Pal[i][j] && Pal[i+1][j-1];
        }
    }
    for(i=0;i<n;i++){
        if(Pal[0][i])
            res[i] = 0;
        else{
            res[i] = INT_MAX;
            for(j=0;j<i;j++){
                if(Pal[j+1][i] && (1+res[j]<res[i]))
                    res[i] = res[j]+1;
            }
        }
    }
    return res[n-1];
}
