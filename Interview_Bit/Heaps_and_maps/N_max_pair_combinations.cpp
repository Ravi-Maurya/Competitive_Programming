vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int n = A.size(),i,j;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    priority_queue<pair<int,pair<int,int>>> maxheap;
    set<pair<int, int>> visited;
    i = n-1;
    j = n-1;
    maxheap.push(make_pair(A[i]+B[j],make_pair(i,j)));
    visited.insert(make_pair(i,j));
    vector<int> res;
    while(n--){
        pair<int,pair<int,int>> top = maxheap.top();
        maxheap.pop();
        res.push_back(top.first);
        i = top.second.first;
        j = top.second.second;
        if(i>0 && j>=0 && visited.find(make_pair(i-1,j))==visited.end()){
            maxheap.push(make_pair(A[i-1]+B[j],make_pair(i-1,j)));
            visited.insert(make_pair(i-1,j));
        }
        if(i>=0 && j>0 && visited.find(make_pair(i,j-1))==visited.end()){
            maxheap.push(make_pair(A[i]+B[j-1],make_pair(i,j-1)));
            visited.insert(make_pair(i,j-1));
        }
    }
    return res;
}
