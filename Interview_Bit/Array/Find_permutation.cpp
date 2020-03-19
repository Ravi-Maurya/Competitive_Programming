vector<int> Solution::findPerm(const string A, int B) {
    int n = A.size(),i;
    int a = 1, b = B;
    vector <int> res;
    for(i=0;i<n;i++){
        if (A[i]=='I'){
            res.push_back(a);
            a++;
        }
        else{
            res.push_back(b);
            b--;
        }
    }
    res.push_back(b);
    return res;
}
