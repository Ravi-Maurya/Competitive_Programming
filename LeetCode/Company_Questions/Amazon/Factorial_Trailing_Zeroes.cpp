class Solution {
public:
    int trailingZeroes(int n) {
        long long int count=0,i=5;
        while(n/i>=1){
            count+=n/i;
            i*=5;
        }
        return count;
    }
};