vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int,int> hash;
    int n=A.size(),i,i1=-1,i2=n+1;
    for(i=0;i<n;i++){
        int tmp = B-A[i];
        if(hash.find(tmp)==hash.end())
            hash[tmp] = i;
        
        if(hash.find(A[i])!=hash.end()){
            if(hash[A[i]]!=i){
                if(i2>i){
                    i1 = hash[A[i]];
                    i2 = i;
                }
            }
        }
    }
    vector<int> res;
    if (i1==-1)
        return res;
    res.push_back(i1+1);
    res.push_back(i2+1);
    return res;
}
