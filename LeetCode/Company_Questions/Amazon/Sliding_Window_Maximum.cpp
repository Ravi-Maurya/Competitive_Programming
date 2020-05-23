class Solution {//O(nlog(k))
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> count;
        int n = nums.size();
        for(int i=0; i<min(n,k);i++){
            count[nums[i]]++;
        }
        vector<int> res;
        res.push_back(count.rbegin()->first);
        for(int i = k; i<n; i++){
            count[nums[i-k]]--;
            count[nums[i]]++;
            if(count[nums[i-k]]==0)
                count.erase(nums[i-k]);
            res.push_back(count.rbegin()->first);
        }
        return res;
    }
};

class Solution {//O(n)
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> res;
        for(int i=0; i<n; i++){
            if(i>=k){
                if(dq.front()==nums[i-k])
                    dq.pop_front();
            }
            while(!dq.empty() && dq.back()<nums[i])
                dq.pop_back();
            dq.push_back(nums[i]);
            if(i>=k-1)
                res.push_back(dq.front());
        }
        return res;
    }
};