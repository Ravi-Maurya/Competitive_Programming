int Solution::atoi(const string A) {
    int i = 0, n=A.size(), sign=1;
    long long int ans = 0;
    while(i<n && A[i]==' ')
        i++;
    if(i<n && A[i]=='-'){
        sign = -1;
        i++;
    }
    else if(i<n && A[i]=='+'){
        sign = 1;
        i++;
    }
    while(i<n){
        if (!('0'<=A[i] && A[i]<='9'))
            return sign*ans;
        ans = ans*10 + (A[i++]-'0');
        if(sign*ans<INT_MIN)
            return INT_MIN;
        if(sign*ans>INT_MAX)
            return INT_MAX;
    }
    return sign*ans;
}
