vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int a=A.size(),i=0;
    int b=B.size(),j=0;
    vector <int> res;
    while (i<a && j<b){
        if (A[i]==B[j]){
            res.emplace_back(A[i]);
            i++;
            j++;
        }
        else if (A[i]<B[j])
            i++;
        else
            j++;
    }
    return res;
}
