class Solution {//O(n3)// BruteForce
public:
    
    bool ispal(string& s, int i, int j){
        while(i<=j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        int idx = -1, res = 0;
        for(int j=0; j<n; j++){
            for(int i=0; i<=j; i++){
                if(ispal(s,i,j) && j-i+1>res){
                    res = j-i+1;
                    idx = i;
                }
                
            }
        }
        if(idx==-1)
            return "";
        return s.substr(idx,res);
    }
};


//O(n2) - Time
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<=1)
            return s;
        bool dp[n+1][n+1];
        memset(dp,false,sizeof(dp));
        for(int i=0; i<n; i++){
            dp[i][i] = true;
        }
        int idx = 0, res = 1;
        for(int i=0; i<n-1; i++){
            dp[i][i+1] = (s[i] == s[i+1]);
            if(dp[i][i+1] && 2>res){
                res = 2;
                idx = i;
            }
        }
        for(int length=3; length<=n; length++){
            for(int i=0; i<n-length+1; i++){
                int j = i+length-1;
                dp[i][j] = dp[i+1][j-1] && (s[i]==s[j]);
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