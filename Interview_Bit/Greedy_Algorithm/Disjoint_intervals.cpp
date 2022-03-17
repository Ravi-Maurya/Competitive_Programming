bool comp(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}
int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(), A.end(), comp);
    int count = 1;
    int e1 = A[0][1];
    for(int i =1; i<A.size(); i++){
        int s = A[i][0];
        int e2 = A[i][1];
        if(s>e1){
            count++;
            e1 = e2;
        }
    }
    return count;
}
