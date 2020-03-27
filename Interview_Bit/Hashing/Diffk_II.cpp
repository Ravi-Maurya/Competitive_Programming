int Solution::diffPossible(const vector<int> &A, int B) {
    unordered_map<int,int> hash;
    int n = A.size(),i;
    for(i=0;i<n;i++){
        int tmp = B+A[i];
        if(hash.find(tmp)==hash.end())
            hash[tmp] = i;
    }
    for(i=0;i<n;i++)
        if(hash.find(A[i]) != hash.end() && hash[A[i]]!=i)
            return 1;
    return 0;
}
