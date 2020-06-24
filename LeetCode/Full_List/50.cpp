class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) 
            return (1 / myPow(x, -(n+1)) / x);
        double res = 1;
        while (n > 0) {
            if (n & 1) {
                res *= x;
            }
            n >>= 1;
            x *= x;
        }
        return res;
    }
};