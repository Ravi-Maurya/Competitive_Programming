vector<int> Solution::solve(vector<int> &A, int B) {
    priority_queue<int, vector<int>, greater<int>> minheap;
    int n = A.size();
    int i = 0;
    while(i<B){
        minheap.push(A[i++]);
    }
    while(i<n){
        int curr = minheap.top();
        if (curr< A[i]){
            minheap.pop();
            minheap.push(A[i]);
        }
        i++;
    }
    vector<int> res;
    while(minheap.size()){
        res.push_back(minheap.top());
        minheap.pop();
    }
    return res;
}
