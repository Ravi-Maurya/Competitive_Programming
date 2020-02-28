vector<int> Solution::getRow(int A) {
    vector<int> res(A+1);
    if(A==0)
        return vector<int>(A+1,1);
    int c = 1;
    res[0] = c;
    for(int i=1;i<=A;i++){
        res[i] = c*(A-i+1)/i;
        c = res[i];
    }
    return res;
}
