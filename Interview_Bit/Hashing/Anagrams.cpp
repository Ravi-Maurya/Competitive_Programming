vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    map<vector<int>,vector<int>> hash;
    int n = A.size(),i;
    for(i=0;i<n;i++){
        vector<int> tmp(26,0);
        int letter = A[i].size();
        for(int j=0;j<letter;j++)
            tmp[(int)(A[i][j]-'a')] += 1;
        if(hash.find(tmp)==hash.end())
            hash[tmp] = {};
        hash[tmp].push_back(i+1);
    }
    vector<vector<int>> res;
    for(auto x:hash)
        res.push_back(x.second);
    sort(res.begin(),res.end());
    return res;
}
