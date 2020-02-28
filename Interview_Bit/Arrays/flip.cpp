vector<int> Solution::flip(string A) {
    int n = A.size(),i;
    vector<int> arr(n);
    vector<int> res;
    for(i=0;i<n;i++){
        if(A[i]=='1')
            arr[i] = -1;
        else
            arr[i] = 1;
    }
    int si=0,curr = 0, max_sum = INT_MIN;
    int start = 0, end = 0;
    for(i=0;i<n;i++){
        curr += arr[i];
        if (curr<0){
            si = i+1;
            curr = 0;
        }
        else if(curr>max_sum){
            start = si;
            end = i;
            max_sum = curr;
        }
    }
    if (max_sum<=0)
        return res;
    res.push_back(start+1);
    res.push_back(end+1);
    return res;
}