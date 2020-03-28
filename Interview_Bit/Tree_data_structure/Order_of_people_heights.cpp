vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    map<int,int,greater<int>> mapping;
    int n = A.size();
    for(int i=0;i<n;i++)
        mapping[A[i]] = B[i];
    vector<int> res;
    for(auto status: mapping){
        if(res.empty())
            res.push_back(status.first);
        else
            res.insert(res.begin()+status.second,status.first);
    }
    return res;
}
