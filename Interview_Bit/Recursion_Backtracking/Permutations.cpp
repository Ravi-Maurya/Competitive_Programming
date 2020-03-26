vector<int> nextPermutation(vector<int> &A) {
    int n = A.size(),i;
    int invert = n-2;
    while (invert>=0 && A[invert]>=A[invert+1]) invert--;
    if (invert==-1){
        return {};
    }
    for(i = n-1; i>=invert+1; i--){
        if (A[i]>A[invert]){
            swap(A[i],A[invert]);
            break;
        }
    }
    reverse(A.begin()+(invert+1),A.end());
    return A;
}


vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> res;
    if(A.size()==1){
        res.push_back(A);
        return res;
    }
    sort(A.begin(),A.end());
    while(true){
        res.push_back(A);
        A = nextPermutation(A);
        if(A.size()==0)
            break;
    }
    return res;
}
