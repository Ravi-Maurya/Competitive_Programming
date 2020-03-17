void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i;
    int n = A.size(),j;
    int m = B.size(),k;
    A.resize(n+m);
    i = n+m-1; j = n-1; k=m-1;
    while(j>=0 && k>=0){
        if (A[j]>=B[k])
            A[i--] = A[j--];
        else
            A[i--] = B[k--];
    }
    while(j<0 && k>=0)
        A[i--]=B[k--];
    while(j>=0 && k<0)
        A[i--]=A[j--];
}
