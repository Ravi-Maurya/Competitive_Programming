class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int Xor = 0;
        int n = nums.size();
        for(int i=0; i<n; i++)
            Xor ^= nums[i];
        int mask = Xor&~(Xor-1);
        int numa = 0, numb = 0;
        for(int i=0; i<n; i++){
            if(mask&nums[i])
                numa ^= nums[i];
            else
                numb ^= nums[i];
        }
        return {numa,numb};
    }
};