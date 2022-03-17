int Solution::solve(vector<int> &A, int B) {
    priority_queue<int, vector<int> > maxheap;
    for(auto row : A)
        maxheap.push(row);
    int profit = 0;
    while(B--){
        int curr_val = maxheap.top();maxheap.pop();
        profit += curr_val;
        curr_val--;
        if(curr_val)
            maxheap.push(curr_val);
    }
    return profit;

}
