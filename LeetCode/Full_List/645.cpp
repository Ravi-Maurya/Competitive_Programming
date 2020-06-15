class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int size = nums.size();
        int Xor = 0, xor0 = 0, xor1 = 0;
        for (int n: nums)
            Xor ^= n;
        for (int i = 1; i <= size; i++)
            Xor ^= i;
        int rightmostbit = Xor & ~(Xor - 1);
        for (int n: nums) {
            if ((n & rightmostbit) != 0)
                xor1 ^= n;
            else
                xor0 ^= n;
        }
        for (int i = 1; i <= size; i++) {
            if ((i & rightmostbit) != 0)
                xor1 ^= i;
            else
                xor0 ^= i;
        }
        for (int i = 0; i < size; i++) {
            if (nums[i] == xor0)
                return {xor0, xor1};
        }
        return {xor1, xor0};
    }
};