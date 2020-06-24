class Solution {
public:
    int power(long long int x, int a) { 
        int res = 1; 
        while (a) { 
            if (a & 1) 
                res = res * x; 
            x = x * x; 
            a >>= 1; 
        } 
        return res; 
    } 
    int integerBreak(int n) {
        // to maximize the product we will divide the n in x equal parts so that
        // n =  x * (n/x);
        // product y = x^(n/x);
        // dy/dx = y*(1 - lnx)/x^2;
        // dy/dx = 0 for maximizing
        // lnx = 1 -> x = e i.e. 2<x<3 so we divide  n either in two values or 3 values;
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        int res;
        int k = n%3;
        if(k==0)
            res = power(3,n/3);
        else if(k==1)
            res = 4*power(3,n/3 - 1);
        else
            res = 2*power(3,n/3);
        return res;
    }
};