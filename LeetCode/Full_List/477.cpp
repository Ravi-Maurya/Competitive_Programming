class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n =nums.size();
        int res = 0;
        for(int i=0; i<32; i++){
            int mask = (1<<i);
            int one = 0, zero = 0;
            for(int j=0; j<n; j++){
                if(mask&nums[j])
                    one++;
                else
                    zero++;
            }
            res += one*zero;
        }
        return res;
    }
};