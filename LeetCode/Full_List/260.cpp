class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int Xor = 0;
        for(auto& x: nums)
            Xor ^= x;
        int mask = Xor&~(Xor-1);
        int Xora = 0, Xorb = 0;
        for(auto& x: nums){
            if(x&mask)
                Xora ^= x;
            else
                Xorb ^= x;
        }
        return {Xora,Xorb};
    }
};