int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int i=0,j=0;
    while (i<n){
        int cnt = 1;
        while(i<n-1 && A[i]==A[i+1]){
            cnt++;
            i++;
        }
        if (cnt==1){
            A[j] = A[i];
            j++;
            i++;
        }
        else if (cnt>1){
            A[j] = A[i];
            j++;
            A[j] = A[i];
            j++;
            i++;
        }
    }
    return j;
}
