int Solution::isPalindrome(int A) {
    if (A<0) return false;
    int divis = floor(log10(A));
    if (divis==0)
        return true;
    divis = pow(10,divis);
    while (A!=0){
        // cout<<divis<<A<<endl;
        if (A/divis != A%10)
            return false;
        A = A%divis;
        A = A/10;
        divis /= 100;
    }
    return true;
}
