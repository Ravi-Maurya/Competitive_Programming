vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> res;
    if(D==0)
        return res;
    int i,a=0,b=0,c=0,nA=A,nB=B,nC=C;
    for(i=0;i<D;i++){
        res.push_back(min(nA,min(nB,nC)));
        if(res[i]==nA){
            nA = res[a]*A;
            a++;
        }
        if(res[i]==nB){
            nB = res[b]*B;
            b++;
        }
        if(res[i]==nC){
            nC = res[c]*C;
            c++;
        }
    }
    return res;
}
