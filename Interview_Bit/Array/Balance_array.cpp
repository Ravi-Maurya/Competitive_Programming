int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<long long int> os(n+1, 0), es(n+1, 0);
    // Fisrt is odd || second is even
    for(int i=1; i<=n; i++){
        if((i%2) == 0){
            os[i] = os[i-1];
            es[i] = es[i-1] + A[i-1];
        }
        else{
            os[i] = os[i-1] + A[i-1];
            es[i] = es[i-1];
        }
    }
    int ans = 0;
    for(int i=1; i<=n ; i++){
        auto o1 = os[i-1];
        auto e1 = es[i-1];
        auto o2 = os[n] - os[i-1];
        auto e2 = es[n] - es[i-1];
        if((i%2) != 0){
            o2 -= A[i-1];
        }
        else{
            e2 -= A[i-1];
        }
        // printf("%d : (%d, %d) || (%d, %d) \n", i, o1, e2, e1, o2);
        if((o1+e2) == (e1+o2)){
            ans++;
        }
    }
    return ans;
}
