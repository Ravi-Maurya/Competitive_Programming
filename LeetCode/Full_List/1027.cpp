class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {//O(n3)
        int n = A.size();
        if(n<2)
            return n;
        int res = 2;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int diff = A[j] - A[i];
                int next = A[j] + diff;
                int curr = 2;
                for(int k=j+1; k<n; k++){
                    if(A[k]==next){
                        next += diff;
                        curr++;
                    }
                }
                res = max(res,curr);
            }
        }
        return res;
    }
};

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        if(n<= 2)
            return n;
        int res = 2;
        vector<unordered_map<int, int>> dp(n);
        for(int i = 1; i < n; i++)
            for(int j = 0; j < i; j++) {
                int diff = (A[i] - A[j]);
                int curr = 1 + (dp[j].count(diff) ? dp[j][diff] : 0);
                int global_max = dp[i].count(diff) ? dp[i][diff] : 2;
                dp[i][diff] = max(global_max, curr);
                res = max(res, dp[i][diff]);
            }
        return res;
    }
};