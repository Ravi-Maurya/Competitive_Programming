int count_zero_sub(vector<int>& tmp){
    int n=tmp.size();
    unordered_map<int, int> count; 
    int res = 0;  
    int currsum = 0; 
    for (int i = 0; i < n; i++) { 
        currsum += tmp[i]; 
        if (currsum == 0)  
            res++;         
        if (count.find(currsum) != count.end())  
            res += (count[currsum]); 
        count[currsum]++; 
    }
    return res;
}

int Solution::solve(vector<vector<int> > &A) {
    int m = A.size();
    if(m==0)
        return 0;
    int n=A[0].size();
    int ans=0;
    for(int i=0;i<m;i++){
        vector<int> t(n,0);
        for(int j=i;j<m;j++){
            for(int k=0;k<n;k++){
                t[k]+=A[j][k];
            }
            ans += count_zero_sub(t);
        }
    }
    return ans;
}
