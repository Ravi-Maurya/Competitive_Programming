class Solution {
public:
    int countPrimes(int n) {
        bool isprime[n+1];
        memset(isprime,true,sizeof(isprime));
        for(int i=2; i*i<n; i++)
            if(isprime[i])
                for(int j=i*i; j<n ; j+=i)
                    isprime[j] = false;
        int res = 0;
        for(int i=2; i<n; i++)
            if(isprime[i])
                res++;
        return res;
    }
};