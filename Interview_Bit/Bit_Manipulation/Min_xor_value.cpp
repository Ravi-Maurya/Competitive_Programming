int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(),A.end());
    int Xor = INT_MAX;
    int n = A.size();
    for(int i=0;i<n-1;i++){
        Xor = (A[i]^A[i+1])<Xor ? (A[i]^A[i+1]): Xor;
    }
    return Xor;
}
