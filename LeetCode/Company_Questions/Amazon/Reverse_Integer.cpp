class Solution {
public:
    int reverse(int x) {
        long long int res = 0;
        if(x == INT_MIN || x==INT_MAX || x==0)
            return res;
        int sign = x<0?-1:1;
        long long tmpx = abs(x);
        while(tmpx){
            long long rem = tmpx%10;
            tmpx = tmpx/10;
            res = res*10 + rem;
            if(sign*res>INT_MAX || sign*res<INT_MIN)
                return 0;
        }
        return sign*res;
    }
};