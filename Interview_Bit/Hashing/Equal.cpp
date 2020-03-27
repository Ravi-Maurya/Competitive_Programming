vector<int> Solution::equal(vector<int> &A) {
    unordered_map<int,pair<int,int>> hash;
    int n = A.size(),i,j;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(hash.find(A[i]+A[j])==hash.end())
                hash[A[i]+A[j]] = make_pair(i,j);
    vector<int> res(4,n+1);
    int a1,b1,c1,d1;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            a1 = hash[A[i]+A[j]].first;
            b1 = hash[A[i]+A[j]].second;
            c1 = i;
            d1 = j;
            if(a1<b1 && c1<d1 && a1<c1 && b1!=d1 && b1!=c1){
                if(a1<res[0] || (a1==res[0] && b1<res[1]) || (a1==res[0] && b1==res[1] && c1<res[2]) || (a1==res[0] && b1==res[1] && c1==res[2] && d1<res[3])){
                    res[0] = a1;
                    res[1] = b1;
                    res[2] = c1;
                    res[3] = d1;
                }
            }
        }
    }
    if(res[0]==n+1)
        return {};
    return res;
}
