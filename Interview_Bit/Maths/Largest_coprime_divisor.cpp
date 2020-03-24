int gcd(int x, int y){
    if(y==0)
        return x;
    return gcd(y,x%y);
}
int Solution::cpFact(int A, int B) {
    while(gcd(A,B)!=1){
        A = A/gcd(A,B);
    }
    return A;
}
