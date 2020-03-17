unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (A==0) return 0;
    unsigned int ans = 0;
    int bits = 32;
    int i;
    for (i=0;i<bits;i++){
        if (A&(1<<i)){
            ans += (1<<(bits-i-1));
        }
    }
    return ans;
}
