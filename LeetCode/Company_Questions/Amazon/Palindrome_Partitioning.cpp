class Solution {
public:
  
  vector<vector<string>> partition(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    //   build dp : if i through j (inclusive) makes a palindrome, dp[i][j] = true;
    for(int l = 1; l <=n; l++){
      for(int i = 0; i < n; i++){
        int j = i + l - 1;
        if(j >= n) break;
        dp[i][j] = (i + 1 > j - 1 || dp[i + 1][j - 1]) && s[i] == s[j];
      }
    }
    
    //  dfs
    vector<string> path;
    vector<vector<string>> result;
    dfs(s, 0, path, result, dp);

    return result;
  }
  
  void dfs(string& s, int start, vector<string>& path, vector<vector<string>>& result, vector<vector<bool>>& dp){
    int n = s.size();
    if(start == n){
      result.push_back(path);
      return;
    } 
    
    for(int i = start; i < n; i++){
      if(!dp[start][i]) continue;
      
      path.push_back(s.substr(start, i - start + 1));
      dfs(s, i + 1, path, result, dp);
      path.pop_back();
    } 
  }
};