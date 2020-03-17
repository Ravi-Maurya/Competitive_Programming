int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int n = A.size();
    if (n<3)
        return 1000000000;
    int ans = 0;
    if (n==3){
        for(int x:A)
            ans+=x;
        return ans;
    }
    ans = A[0]+A[1]+A[2];
    int tmp = abs(ans-B);
    for(int i=0;i<n;i++){
        int j = i+1;
        int k = n-1;
        while (j<k){
            if (abs((A[i]+A[j]+A[k])-B)<=tmp){
                ans = A[i]+A[j]+A[k];
                tmp = abs(ans-B);
            }
            if ((A[i]+A[j]+A[k])<B)
                j++;
            else
                k--;
        }
    }
    return ans;
}
