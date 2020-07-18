class Solution {
public:
    int reverse(int x) {
        long long int n = abs(x), res = 0;
        int sign = x<0?-1:1;
        while(n){
            int curr = n%10;
            res = res*10 + curr;
            n /= 10;
            if(res*sign<INT_MIN)
                return 0;
            if(res*sign > INT_MAX)
                return 0;
        }
        return sign*res;
    }
};