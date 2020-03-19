vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size(),Xor = 0,i;
    for(i=0;i<n;i++){
        Xor ^= A[i];
        Xor ^= (i+1);
    }
    int mask = Xor&~(Xor-1);
    int XorA = 0, XorB = 0;
    for(i=0;i<n;i++){
        if (mask&A[i])
            XorA ^= A[i];
        else
            XorB ^= A[i];
        
        if (mask&(i+1))
            XorA ^= (i+1);
        else
            XorB ^= (i+1);
    }
    for(i=0;i<n;i++){
        if (A[i]==XorA){
            vector <int> res;
            res.push_back(XorA);
            res.push_back(XorB);
            return res;
        }
        else if (A[i]==XorB){
            vector <int> res;
            res.push_back(XorB);
            res.push_back(XorA);
            return res;
        }
    }
}
