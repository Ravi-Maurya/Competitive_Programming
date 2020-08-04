class Solution {
public:
    bool isPowerOfFour(int x) {
        if(x<1)
            return false;
        if((x&(x-1)) != 0)
            return false;
        while(x>0){
            if(x==1)
                return true;
            x >>= 2;
        }
        return false;
    }
};