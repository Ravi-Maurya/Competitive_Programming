class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> ump;
        ump[0] = -1;
        int res = 0, count = 0;
        for(int i=0; i<nums.size(); i++){
            count += (nums[i]?1:-1);
            if(ump.count(count))
                res = max(res,i-ump[count]);
            else
                ump[count] = i;
        }
        return res;
    }
};