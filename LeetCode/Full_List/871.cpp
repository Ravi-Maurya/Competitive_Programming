class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<long long> dp(n+1,0);
        dp[0] = startFuel;
        for(int i=0; i<n; i++){
            for(int j=i; j>=0; j--){
                if(dp[j] >= stations[i][0])
                    dp[j+1] = max(dp[j+1], dp[j] + stations[i][1]);
            }
        }
        for(int i=0; i<=n; i++)
            if(dp[i]>=target)
                return i;
        return -1;
    }
};

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int res = 0, prev = 0;
        for(auto station: stations){
            int x = station[0];
            int l = station[1];
            startFuel -= x - prev;
            while(!pq.empty() && startFuel<0){
                startFuel += pq.top();
                pq.pop();
                res++;
            }
            if(startFuel<0)
                return -1;
            pq.push(l);
            prev = x;
        }
        startFuel -= target - prev;
        while(!pq.empty() && startFuel<0){
            startFuel += pq.top();
            pq.pop();
            res++;
        }
        if(startFuel<0)
            return -1;
        return res;
    }
};