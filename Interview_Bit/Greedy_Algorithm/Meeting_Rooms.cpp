int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    vector<int> start(n), en(n);
    for(int i=0; i<n; i++){
        start[i] = A[i][0];
        en[i] = A[i][1];
    }
    sort(start.begin(), start.end());
    sort(en.begin(), en.end());
    int i = 0, j = 0, ans = 0;
    while(i<n){
        ans++;
        if(start[i]>=en[j]){
            ans--;
            j++;
        }
        i++;
    }
    return ans;
}
