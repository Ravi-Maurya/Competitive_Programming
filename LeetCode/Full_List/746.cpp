class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()<3)
            return 0;
        cost.push_back(0);
        int n = cost.size();
        int f = cost[0];
        int s = cost[1],res;
        for(int i=2; i<n; i++){
            res = cost[i] + min(f,s);
            f = s;
            s = res;
        }
        return res;
    }
};