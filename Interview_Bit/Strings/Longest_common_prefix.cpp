string Solution::longestCommonPrefix(vector<string> &A) {
    int n = A.size();
    if(n==0)
        return "";
    if(n==1)
        return A[0];
    sort(A.begin(),A.end());
    int size = min(A[0].size(),A[n-1].size());
    int i=0;
    while(i<size && A[0][i]==A[n-1][i])
        i++;
    return A[0].substr(0,i);
}
