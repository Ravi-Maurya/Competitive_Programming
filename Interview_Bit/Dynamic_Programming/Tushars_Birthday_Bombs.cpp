// Greedy Approach <================
// <-------------> Naive One
vector<int> Solution::solve(int A, vector<int> &B) {
    int n = B.size();
    int idx = 0;
    int minstrength = B[idx];
    for(int i=1;i<n;i++){
        if(minstrength>B[i]){
            minstrength = B[i];
            idx = i;
        }
    }
    int kicks = A/minstrength;
    vector<int> res(kicks,idx);
    int sum = minstrength*kicks, c=0,i=0;
    while(c<kicks && i<idx){
        int tmp = sum - B[res[c]] + B[i];
        if(tmp>sum && tmp<=A){
            res[c++]=  i;
            sum = tmp;
        }
        else
            i++;
    }
    return res;
}
// Dynamic Programming Approach <==============
// ---------------------------- Knapsack Kind of
vector<int> Solution::solve(int A, vector<int> &B) {
    int n = B.size();
    vector<int> dp(A+1, -1), backtrack(A+1);
    backtrack[0] = 0;
    for(int i=0;i<=A;i++){
        for(int j=0;j<n;j++){
            if(i>=B[j] && dp[i]<dp[i-B[j]]+1){
                dp[i] = dp[i-B[j]]+1;
                backtrack[i] = j;
            }
        }
    }
	vector<int> res;
	int i = A;
	while(i>=0 && (i-B[backtrack[i]])>=0){
	    res.push_back(backtrack[i]);
	    i -= B[backtrack[i]];
	}
	return res;
}
