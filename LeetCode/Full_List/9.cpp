class Solution {
public:
    bool isPalindrome(int x) {
        if(x==0)
            return true;
        if(x<0 || ((x%10)==0))
            return false;
        int curr = 0;
        while(x>curr){
            curr = curr*10 + x%10;
            x /= 10;
        }
        return (x==curr || x==(curr/10));
    }
};