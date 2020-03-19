int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int c1 = 0, c2=0,i;
    int min1=INT_MAX, min2=INT_MAX;
    for(i=0;i<n;i++){
        if(min1==A[i])
            c1++;
        else if(min2==A[i])
            c2++;
        else if (c1==0){
            c1++;
            min1=A[i];
        }
        else if (c2==0){
            c2++;
            min2=A[i];
        }
        else{
            c1--;
            c2--;
        }
    }
    c1 = 0; c2=0;
    for(i=0;i<n;i++){
        if (min1==A[i])
            c1++;
        else if (min2==A[i])
            c2++;
    }
    if (c1>n/3)
        return min1;
    if (c2>n/3)
        return min2;
    return -1;
}
