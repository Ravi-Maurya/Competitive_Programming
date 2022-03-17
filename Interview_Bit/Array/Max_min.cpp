int Solution::solve(vector<int> &A) {
    int max_val = INT_MIN, min_val = INT_MAX;
    for(auto i: A){
        max_val = max(max_val, i);
        min_val = min(min_val, i);
    }
    return max_val + min_val;
}
