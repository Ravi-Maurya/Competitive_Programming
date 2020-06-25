class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minheap;
        for(int i = 0; i<nums.size(); i++){
            if(minheap.size()<k)
                minheap.push(nums[i]);
            else{
                if(minheap.top()<nums[i]){
                    minheap.push(nums[i]);
                    minheap.pop();
                }
            }
        }
        int res = minheap.top();
        return res;
    }
};


class Solution {
public:
    
    int partition(vector<int>& nums, int l, int h){
        int piviot = nums[h];
        int i = l;
        for(int j=l;j<h;j++)
            if(nums[j]<=piviot)
                swap(nums[i++],nums[j]);
        swap(nums[i],nums[h]);
        return i;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size()-k;
        int l = 0, h = nums.size()-1;
        while(l<h){
            int p = partition(nums,l,h);
            if(p==k)
                break;
            if(p<k)
                l = p+1;
            else
                h = p-1;
        }
        return nums[k];
    }
};