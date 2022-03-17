typedef pair<int, pair<int,int>> pii;
vector<int> Solution::solve(vector<vector<int> > &A) {
    int k = A.size();
    int n = A[0].size();
    // cout<< n << " " << k << "\n";
    priority_queue<pii, vector<pii>, greater<pii>> minheap;
    for(int i=0; i<k; i++)
        minheap.push(make_pair(A[i][0], make_pair(i,0)));
    vector<int> res;
    // cout<< minheap.size() << "\n";
    while(minheap.size()){
        auto top = minheap.top(); minheap.pop();
        res.push_back(top.first);
        auto idx = top.second;
        auto i = idx.first;
        auto j = idx.second;
        j += 1;
        if(j<n)
            minheap.push(make_pair(A[i][j], make_pair(i,j)));
    }
    return res;
}
