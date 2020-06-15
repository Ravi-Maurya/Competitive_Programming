class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1)
            return true;
        if(n==0 || n%3!=0)
            return false;
        if(n<3)
            return false;
        n = abs(n);
        while(n>0){
            n /= 3;
            if(n%3!=0 && n!=1)
                return false;
        }
        return true;
    }
};