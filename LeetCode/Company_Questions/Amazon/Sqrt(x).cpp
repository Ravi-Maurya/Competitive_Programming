class Solution {
public:
    int mySqrt(int x) {
        long long int l = 0, h = x, ans, mid;
        while(l<=h){
            mid = (l+h)/2;
            if(mid*mid==x)
                return mid;
            else if(mid*mid<x){
                l =  mid+1;
                ans = mid;
            }
            else
                h = mid-1;
        }
        return ans;
    }
};