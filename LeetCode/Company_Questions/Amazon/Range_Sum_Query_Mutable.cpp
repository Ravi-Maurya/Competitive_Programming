class NumArray {
public:
    vector<int> tree;
    int n;
    void build(vector<int>& nums){
        for(int i=n,j=0; i<2*n; i++,j++)
            tree[i] = nums[j];
        for(int i=n-1;i>0;i--)
            tree[i]=tree[i*2] + tree[1+ i*2];
    }
    NumArray(vector<int>& nums) {
        if(nums.size()>0){
            n = nums.size();
            tree.clear();
            tree.resize(2*n);
            build(nums);
        }
    }
    
    void update(int pos, int val) {
        pos += n;
        tree[pos] = val;
        while(pos>0){
            int left = pos;
            int right = pos;
            if(pos%2==0)
                right = pos+1;
            else
                left = pos-1;
            tree[pos/2] = tree[left] + tree[right];
            pos /= 2;
        }
    }
    
    int sumRange(int l, int r) {
        l += n;
        r += n;
        int sum = 0;
        while(l<=r){
            if(l%2 == 1)
                sum += tree[l++];
            if(r%2 == 0)
                sum += tree[r--];
            l /= 2;
            r /= 2;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */