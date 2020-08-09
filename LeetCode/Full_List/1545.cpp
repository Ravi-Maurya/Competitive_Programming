class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1)
            return '0';
        int x = 1<<(n-1);
        if(k == x)
            return '1';
        if(k>x){
            int y = 2*x-k;
            char ch = findKthBit(n-1,y);
            if(ch=='0')
                return '1';
            return '0';
        }
        int y = k;
        char ch = findKthBit(n-1,y);
        return ch;
    }
};