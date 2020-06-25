class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        vector<int> count(n,0);
        for(int i=0; i<n; i++)
            count[nums[i]]++;
        for(int i=0; i<n; i++)
            if(count[i]>1)
                return i;
        return -1;
    }
};