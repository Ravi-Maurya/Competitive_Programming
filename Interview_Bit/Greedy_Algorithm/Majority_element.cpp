int Solution::majorityElement(const vector<int> &A) {
    vector<int> B(A.size());
    for(int i=0;i<A.size();i++)
        B[i] = A[i];
    sort(B.begin(),B.end());
    int x = A.size()/2;
    return B[x];
}
