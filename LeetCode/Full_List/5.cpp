//O(n2) - Time
class Solution {//O(n2) - space
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        int idx = 0;
        int res = 0;
        for(int length=1; length<=n; length++){
            for(int i = 0; i<n-length+1; i++){
                int j = i+length-1;
                if(length==1){
                    dp[i][j] = 1;
                }
                else if(length == 2){
                    dp[i][j] = (s[i]==s[j]);
                }
                else{
                    dp[i][j] = dp[i+1][j-1] && (s[i]==s[j]);
                }
                
                if(dp[i][j] && length>res){
                    res = length;
                    idx = i;
                }
            }
        }
        return s.substr(idx,res);
    }
};

class Solution {//O(1) space;
public:
    
    int expand(string s, int left, int right){
        int l = left, r = right;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;r++;
        }
        return r-l-1;
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<2)
            return s;
        int st = 0,en =0;
        for(int i=0; i<n; i++){
            int l1 = expand(s,i,i);//ODD
            int l2 = expand(s,i,i+1);//Even
            int l = max(l1,l2);
            cout<< l << " ";
            if(l> en-st+1){
                // cout<< st << " "<<en<<"\n";
                st = i - (l-1)/2;
                en = i + l/2;
            }
        }
        // cout<< st << " "<<en<<"\n";
        return s.substr(st,en - st+1);
    }
};