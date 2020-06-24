class Solution {
public:
    int numSquares(int n) {//O(nsqrt(n))
        if(n<4)
            return n;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = i;
            for(int j=1; j*j<=i; j++){
                dp[i] = min(dp[i],1+dp[i-(j*j)]);
            }
        }
        return dp[n];
    }
};


class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        unordered_set<int> visited;
        int res = 0;
        q.push(0);
        visited.insert(0);
        while(!q.empty()){
            int size = q.size();
            res++;
            while(size--){
                int u = q.front();q.pop();
                for(int i=1; i*i<=n; i++){
                    int v = u + i*i;
                    if(v==n)
                        return res;
                    if(v>n)
                        break;
                    if(!visited.count(v)){
                        visited.insert(v);
                        q.push(v);
                    }
                }
            }
        }
        return res;
    }
};