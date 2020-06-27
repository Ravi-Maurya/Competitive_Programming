class NumArray {
public:
    vector<int> prefixsum;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixsum.resize(n+1,0);
        for(int i=0 ;i<n; i++){
            prefixsum[i+1] = nums[i]+prefixsum[i];
        }
    }
    
    int sumRange(int i, int j) {
        return prefixsum[j+1]-prefixsum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */