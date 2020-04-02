int Solution::climbStairs(int A) {
    int f = 1;
    if(A==1)
        return f;
    int s = 2;
    if(A==2)
        return s;
    int third;
    for(int i=3;i<=A;i++){
        third = f+s;
        f = s;
        s = third;
    }
    return third;
}
