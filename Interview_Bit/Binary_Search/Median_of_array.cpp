double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m = A.size();
    int n = B.size();
    if (m>n){
        return findMedianSortedArrays(B,A);
    }
    int min_index = 0, max_index = m,i,j,median;
    while (min_index<=max_index){
        i = (min_index+max_index)/2;
        j = (n+m+1)/2 - i;
        if (i<m && j>0 && B[j-1]>A[i])
            min_index = i+1;
        else if (j<n && i>0 && A[i-1]>B[j])
            max_index = i-1;
        else{
            if (i==0)
                median = B[j-1];
            else if (j==0)
                median = A[i-1];
            else
                median = max(A[i-1],B[j-1]);
            break;
        }
    }
    
    if ((n+m)&1 == 1)
        return (double)median;
    if (i==m)
        return (median+B[j])/2.0;
    if (j==n)
        return (median+A[i])/2.0;
    return (median + min(A[i],B[j]))/2.0;
}
