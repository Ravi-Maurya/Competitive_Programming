int Solution::lengthOfLongestSubstring(string A) {
    unordered_map<char,int> alphabets;
    int n = A.size(),i=0,j=0,res=0;
    while(i<n){
        if(alphabets.find(A[i])==alphabets.end())
            alphabets[A[i]] = -1;
        if(j<=alphabets[A[i]])
            j = alphabets[A[i]]+1;
        alphabets[A[i]] = i;
        i+=1;
        res = max(res,i-j);
    }
    return res;
}
