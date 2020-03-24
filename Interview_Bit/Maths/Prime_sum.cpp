vector<bool> sieve(int n){
    vector<bool> isprime(n+1,true);
    isprime[0] = false;
    isprime[1] = false;
    for(int i=2;i*i<=n;i++)
        if(isprime[i])
            for(int j=i*2; j<=n;j+=i)
                isprime[j]=false;
    
    return isprime;
}

vector<int> Solution::primesum(int A) {
    vector<bool> isP;
    isP = sieve(A);
    vector<int> res(2);
    for(int i=2;i<=A/2;i++)
        if(isP[i] && isP[A-i]){
            res[0] = i;
            res[1] = A-i;
            return res;
        }
}