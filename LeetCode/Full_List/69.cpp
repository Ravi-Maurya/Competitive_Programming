class Solution {
public:
    int mySqrt(int x) {
        if(x<=1)
            return x;
        int i = 0, j = ceil(x/2);
        while(i<j){
            int curr = i + (j-i+1)/2;
            long long int y =(long long)curr * curr;
            if(y <= x)
                i = curr;
            else
                j = curr-1;
        }
        return i;
    }
};