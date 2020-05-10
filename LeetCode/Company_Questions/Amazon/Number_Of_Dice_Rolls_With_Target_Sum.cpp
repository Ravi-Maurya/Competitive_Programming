const int mod = 1e9 + 7;
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<int> ways(target +1);
        ways[0] = 1;
        for(int repeat = 1; repeat<=d; ++repeat){
            vector<int> new_ways(target +1);
            for(int already = 0; already<=target; ++already){
                for(int face=1; face<=f; ++face){
                    if(already+face <= target){
                        int& tmp = new_ways[already+face];
                        tmp += ways[already];
                        if(tmp>=mod)
                            tmp -= mod;
                    }
                }
            }
            ways = new_ways;
        }
        return ways[target];
    }
};