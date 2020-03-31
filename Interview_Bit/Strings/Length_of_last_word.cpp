int Solution::lengthOfLastWord(const string A) {
    int n = A.size();
    int i = n-1;
    while(i>=0 && A[i]==' ')
        i--;
    int x = i;
    while(i>=0 && A[i]!=' ')
        i--;
    return x-i;
}
