class Solution {
public:
    int titleToNumber(string A) {
        int n = A.size();
        int ans = 0,i;
        for(i=0;i<n;i++){
            ans *= 26;
            ans += A[i]-'A'+1;
        }
        return ans;
    }
};