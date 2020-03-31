int Solution::isPalindrome(string A) {
    int n = A.size(),i,j;
    i = 0;
    j = n-1;
    while(i<=j){
        if(isalnum(A[i])==0)
            i++;
        else if(isalnum(A[j])==0)
            j--;
        else{
            if(tolower(A[i])!=tolower(A[j]))
                return 0;
            i++;
            j--;
        }
    }
    return 1;
}
