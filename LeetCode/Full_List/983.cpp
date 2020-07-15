class Solution {
public:
    int dp[370];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int solve(unordered_set<int>& days, vector<int>& costs, int i){
        if(i>365)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int res = INT_MAX;
        if(days.count(i)){
            res = min({solve(days,costs,i+1)+costs[0],
                      solve(days,costs,i+7)+costs[1],
                      solve(days,costs,i+30)+costs[2]});
        }
        else{
            res = solve(days,costs,i+1);
        }
        return dp[i] = res;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> d(days.begin(),days.end());
        return solve(d,costs,1);
    }
};


class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int day = days[days.size()-1];
        int dp[day+1];
        memset(dp,0,sizeof(dp));
        bool travel[day+1];
        memset(travel,false,sizeof(travel));
        for(int i=0; i<days.size(); i++){
            travel[days[i]] = true;
        }
        for(int i=1; i<=day; i++){
            if(!travel[i]){
                dp[i] = dp[i-1];
                continue;
            }
            dp[i] = min({
                dp[i-1] + costs[0],
                dp[max(0,i-7)] + costs[1],
                dp[max(0,i-30)] + costs[2]
            });
        }
        return dp[day];
    }
};