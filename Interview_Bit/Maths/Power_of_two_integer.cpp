int Solution::isPower(int A) {
    if (A<=1)
        return 1;
    for(int i=2;i*i<=A;i++){
        int val = log(A)/log(i);
        if (pow(i,val)==A){
            return 1;
        }
    }
    return 0;
}
