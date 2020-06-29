class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        nums.push_back(INT_MIN);
        int n = nums.size();
        deque<int> dq;
        vector<int> res;
        for(int i=0; i<n; i++){            
            while(!dq.empty() && nums[dq.back()]<=nums[i])
                dq.pop_back();
            while(!dq.empty() && dq.front()<=(i-k))
                dq.pop_front();
            dq.push_back(i);
            if(i>=k-1 && i!=n-1)
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};

class Solution {//prefix max, suffix max
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==1)
            return nums;
        vector<int> left(n), right(n);
        left[0] = nums[0];
        right[n-1] = nums[n-1];
        for(int i=1; i<n; i++){
            if(i%k==0)
                left[i] = nums[i];
            else
                left[i] = max(left[i-1],nums[i]);
            
            int j = n-i-1;
            if((j+1)%k==0)
                right[j] = nums[j];
            else
                right[j] = max(right[j+1],nums[j]);
        }
        vector<int> res(n-k+1);
        for(int i=0; i<n-k+1; i++)
            res[i] = max(left[i+k-1],right[i]);
        return res;
    }
};