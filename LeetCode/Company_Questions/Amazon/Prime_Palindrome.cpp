class Solution {
public:
    bool isPrime(int n){
        if(n<2)
            return false;
        if(n<4)
            return true;
        int r = sqrt(n);
        for(int d=2; d<=r; ++d)
            if(n%d==0)
                return false;
        return true;
    }
    
    int reverse(int n){
        int ans = 0;
        while(n){
            ans = 10*ans + (n%10);
            n /= 10;
        }
        return ans;
    }
    
    int primePalindrome(int N) {
        while(true){
            if(N==reverse(N) && isPrime(N))
                return N;
            N++;
            if(10000000 < N && N<100000000)
                N = 100000000;
        }
    }
};