class Solution {
public:
    struct Bucket{
        bool used = false;
        int minval = INT_MAX;
        int maxval = INT_MIN;
    };
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n<2)
            return 0;
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        int bucket_size = max(1, (mx-mn)/(n-1));
        int bucket_num = (mx-mn)/bucket_size + 1;
        vector<Bucket> buckets(bucket_num);
        for(auto& num: nums){
            int idx = (num-mn)/bucket_size;
            buckets[idx].used = true;
            buckets[idx].minval = min(num, buckets[idx].minval);
            buckets[idx].maxval = max(num, buckets[idx].maxval);
        }
        int prevBucket = mn, max_gap = 0;
        for(auto bucket: buckets){
            if(!bucket.used)
                continue;
            max_gap = max(max_gap, bucket.minval - prevBucket);
            prevBucket = bucket.maxval;
        }
        return max_gap;
    }
};