class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size())
            return 0;
        unordered_set<int> ust;
        for(auto x: nums)
            ust.insert(x);
        int res = 1;
        for(auto x=ust.begin(); x!= ust.end(); x++){
            if(!ust.count(*x-1)){
                int curr = *x;
                int streak = 1;
                while(ust.count(curr+1)){
                    curr++;
                    streak++;
                }
                res = max(res,streak);
            }
        }
        return res;
    }
};