class Solution {
public:
    string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n,vector<bool>(n,0));
    int mx = 1;
    for(int i=0;i<n;i++)
        dp[i][i] = 1;
    int st = 0;
    for(int i=0;i<n-1;i++)
        if(s[i]==s[i+1]){
            dp[i][i+1] = 1;
            if(2>mx){
                st = i;
                mx = 2;
            }
        }
    for(int len = 3; len<=n; len++){
        for(int i=0; i<n-len+1; i++){
            int j = i+len-1;
            if(dp[i+1][j-1] && s[i]==s[j]){
                dp[i][j] = 1;
                if(len>mx){
                    st = i;
                    mx = len;
                }
            }
        }
    }
    return s.substr(st,mx);
    // string res = "";
    // for(int i=st; i<st+mx; i++)
    //     res += s[i];
    // return res;
    }
};