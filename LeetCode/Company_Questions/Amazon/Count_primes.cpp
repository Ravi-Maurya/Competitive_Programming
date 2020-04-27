class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)
            return 0;
        if(n<=3)
            return 1;
        vector<bool> prime(n+1,true);
        for(int p=2; p*p<=n; p++)
            if(prime[p]){
                for(int i=p*p; i<=n; i+=p)
                    prime[i] = false;
            }
        int res = 0;
        for(int p=2; p<=n;p++)
            if(prime[p])
                res++;
        if(prime[n])
            res -= 1;
        return res;
    }
};