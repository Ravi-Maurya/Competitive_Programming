# define MOD 1000000007
int Solution::maxSpecialProduct(vector<int> &A) {
    int n = A.size(),i;
    if (n<=2)
        return 0;
    vector <long long int> left_special(n), right_special(n);
    left_special[0] = 0;
    left_special[n-1] = 0;
    right_special[0] = 0;
    right_special[n-1] = 0;
    for(i=1;i<n-1;i++){
        if (A[i-1]>A[i])
            left_special[i] = i-1;
        else if (A[left_special[i-1]]>A[i])
            left_special[i] = left_special[i-1];
        else
            left_special[i] = 0;
        
        if (A[n-i-1]<A[n-i])
            right_special[n-i-1] = n-i;
        else if (A[n-i-1]<A[right_special[n-i]])
            right_special[n-i-1] = right_special[n-i];
        else
            right_special[n-i-1] = 0;
    }
    long long int res = 0;
    for(i=1;i<n-1;i++){
        long long int tmp = left_special[i]*right_special[i];
        res = res<tmp ?tmp :res ;
    }
    return (int)(res%MOD);
}
