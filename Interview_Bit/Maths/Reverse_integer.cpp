int Solution::reverse(int A) {
    long long ans = 0;
    int sign = A<0 ? -1:1;
    A = abs(A);
    while(A!=0){
        ans = ans*10 + A%10;
        A = A/10;
    }
    ans = sign*ans;
    if (INT_MIN<= ans && ans <=INT_MAX)
        return ans;
    return 0;
}