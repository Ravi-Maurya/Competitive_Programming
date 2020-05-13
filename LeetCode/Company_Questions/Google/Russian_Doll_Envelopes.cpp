class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if(!n)
            return 0;
        sort(envelopes.begin(),envelopes.end(),compare);
        int res= 1;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(envelopes[j][0]<envelopes[i][0] && envelopes[j][1]<envelopes[i][1] && dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                    if(res<dp[i])
                        res = dp[i];
                }
            }
        }
        return res;
    }
};