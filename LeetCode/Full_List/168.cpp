class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while(n>0){
            int t = n%26;
            n = n/26;
            if(t==0){
                res += 'Z';
                n -= 1;
            }
            else{
                res += (t + 'A' - 1);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};