vector<int> Solution::lszero(vector<int> &A) {
    int n = A.size();
    int temp = 0, li =-1, ri=-1,size=0;
    map<int,int> hash;
    for(int i=0;i<n;i++){
        temp += A[i];
        if (temp==0){
            if (size<i+1){
                size = i+1;
                ri = i;
                li = -1;
            }
        }
        else if(hash.find(temp)!=hash.end()){
            if(size<i-hash[temp]){
                size = i-hash[temp];
                ri = i;
                li = hash[temp];
            }
        }
        else
            hash[temp] = i;
    }
    vector<int> res;
    for(int i=li+1;i<=ri;i++)
        res.push_back(A[i]);
    return res;
}
