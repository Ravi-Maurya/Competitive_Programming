class Solution {
public:
    int minCut(const string& s) {
        vector<vector<bool>> isPalindrome(s.length(), vector<bool>(s.length(), false));
        
        for (int r = 0; r < s.length(); ++r) {
            for (int l = r; l >= 0; --l) {
                if (r - l == 0 || s[r] == s[l] && r - l == 1) {
                    isPalindrome[l][r] = true;
                } else {
                    isPalindrome[l][r] = isPalindrome[l+1][r-1] && (s[l] == s[r]);
                }
            }
        }
        
        vector<int> dp(s.length()+1, INT_MAX);
        dp[0] = -1;
        
        for (int r = 1; r <= s.length(); ++r) {
            for (int l = r; l > 0; --l) {
                if (isPalindrome[l-1][r-1]) {
                    dp[r] = min(dp[r], dp[l-1]+1);
                }
            }
        }
        
        return dp.back();
    }
};