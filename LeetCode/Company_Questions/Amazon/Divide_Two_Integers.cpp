class Solution {
public:
    int divide(long long int dividend, long long int divisor) {
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        dividend = abs(dividend); 
        divisor = abs(divisor);
        long long int quot = 0, tmp = 0;
        for(int i=31; i>=0; --i){
            if(tmp + (divisor<<i) <= dividend){
                tmp += (divisor<<i);
                quot |= 1ll << i;
            }
        }
        if(INT_MIN<= sign*quot && sign*quot<=INT_MAX)
            return sign*quot;
        return INT_MAX;
    }
};