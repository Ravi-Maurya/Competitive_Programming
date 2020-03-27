int Solution::candy(vector<int> &A) {
    int n = A.size();
    vector<int> candies(n,1);
    for(int i=1;i<n;i++){
        if(A[i]==A[i-1])
            continue;
        else if(A[i]>A[i-1] && candies[i]<=candies[i-1])
            candies[i] = candies[i-1]+1;
        else{
            int j = i-1;
            while(j>=0 && A[j]>A[j+1] && candies[j]<=candies[j+1]){
                candies[j] = candies[j+1]+1;
                j--;
            }
        }
    }
    int res = 0;
    for(auto c:candies)
        res+=c;
    return res;
}
