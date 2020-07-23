class Solution {
public:
    bool confusingNumber(int num) {//2,3,4,5,7
        int n = 0;
        int N = num;
        while(N){
            int x = N%10;
            if(x==2 || x==3|| x==4 || x==5 || x==7)
                return false;
            else{
                if(x==0)
                    n = n*10 + 0;
                else if(x==1)
                    n = n*10 + 1;
                else if(x==6)
                    n = n*10 + 9;
                else if(x==8)
                    n = n*10 + 8;
                else if(x==9)
                    n = n*10 + 6;
                
            }
            N = N/10;
        }
        return num!=n;
    }
};