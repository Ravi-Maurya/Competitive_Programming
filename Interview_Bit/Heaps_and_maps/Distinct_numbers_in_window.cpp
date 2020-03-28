vector<int> Solution::dNums(vector<int> &A, int B) {
    int n = A.size();
    vector<int> res;
    if(n<B)
        return res;
    map<int,int> window;
    for(int i=0;i<B;i++){
        if(window.find(A[i])==window.end())
            window[A[i]] = 1;
        else
            window[A[i]] += 1;
    }
    res.push_back(window.size());
    for(int i=B;i<n;i++){
        auto it = window.find(A[i-B]);
        if(it->second == 1)
            window.erase(it);
        else
            it->second -= 1;
        
        if(window.find(A[i])==window.end())
            window[A[i]] = 1;
        else
            window[A[i]] += 1;
        res.push_back(window.size());
    }
    return res;
}
