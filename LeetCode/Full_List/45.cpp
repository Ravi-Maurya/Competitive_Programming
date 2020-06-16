class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)
            return 0;
        int jumps = 1;
        int maxjump = nums[0];
        int nxtjump = nums[0];
        for(int i=1; i<n; i++){
            if(i>nxtjump)
                return -1;
            if(i+nums[i]>nxtjump)
                nxtjump = i + nums[i];
            if(i==maxjump && i!=(n-1)){
                maxjump = nxtjump;
                jumps++;
            }
        }
        return jumps;
    }
};