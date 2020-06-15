class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        for(int i = 0; i<k;i++){
            while(!dq.empty() && nums[dq.back()]<=nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        vector<int>res;
        for(int i=k; i<=n; i++){
            res.push_back(nums[dq.front()]);
            if(i==n)
                break;
            while(!dq.empty() && nums[dq.back()]<=nums[i])
                dq.pop_back();
            while(!dq.empty() && dq.front()<=(i-k))
                dq.pop_front();
            dq.push_back(i);
        }
        return res;
    }
};