int Solution::divide(int A, int B) {
    if (B == 0) return INT_MAX;
    long long b = B, a = A;
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    long long res = 0;
    while (a >= b) {
        long long v = b;
        long long n = 1;
        while (v+v < a) {
            v += v;
            n += n;
        }
        a -= v;
        res += n;
    }
    if (A < 0) res = -res;
    if (B < 0) res = -res;
    if ((int)res != res) return INT_MAX;
    return res;
}
