vector<vector<int> > Solution::threeSum(vector<int> &A) {
    int B = 0;
    sort(A.begin(),A.end());
    int n = A.size();
    vector <vector<int>> res;
    if (n<3)
        return res;
    int ans = 0;
    if (n==3){
        for(int x:A)
            ans+=x;
        if (ans==0)
            res.emplace_back(A);
        return res;
    }
    map<vector<int>,bool> m;
    for(int i=0;i<n;i++){
        // cout<<i<<endl;
        int j = i+1;
        int k = n-1;
        while (j<k){
            if (A[i]+A[j]+A[k]==B){
                vector <int> tmp(3);
                tmp[0] = A[i];
                tmp[1] = A[j];
                tmp[2] = A[k];
                if (m.find(tmp)==m.end()){
                    res.emplace_back(tmp);
                    m[tmp] = true;
                }
            }
            if ((A[i]+A[j]+A[k])<B)
                j++;
            else
                k--;
        }
    }
    return res;
}
