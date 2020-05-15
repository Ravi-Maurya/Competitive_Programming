class Solution {
public:
    int lastRemaining(int n) {
        int ans = 0;
        int flip = 0;
        int power = 1;
        while (n > 1) {
            int pos = (ans > 0);
            int tmp = n & 1;
            ans |= (((1 ^ tmp) & flip) ^ pos) * power;
            n >>= 1;
            power <<= 1;
            flip ^= 1;
        }
        if (!ans)
            ans |= power;
        return ans;
    }
};