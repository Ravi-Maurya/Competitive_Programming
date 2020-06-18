class Solution {
public:
    bool isprime(long long n){
        if(n<2)
            return false;
        for(long long i = 2; i*i<=n; i++)
            if(n%i==0)
                return false;
        return true;
    }
    int primePalindrome(int N) {
        long long int x;
        if(N<=2)
            return 2;
        if(N<=3)
            return 3;
        if(N<=5)
            return 5;
        if(N<=7)
            return 7;
        for(int i = 1; i<100000; i++){
            string s = to_string(i);
            string z(s.rbegin(),s.rend());
            x = stoll(s + z.substr(1));
            if(x>=N && isprime(x))
                return x;
            x = stoll(s + z);
            if(x>=N && isprime(x))
                return x;
        }
        return -1;
    }
};