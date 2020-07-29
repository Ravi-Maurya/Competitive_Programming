class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, h = n-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[l]<=nums[mid]){
                if(nums[l]<=target && target<=nums[mid])
                    h = mid-1;
                else
                    l = mid+1;
            }
            else{
                if(nums[mid]<=target && target<=nums[h])
                    l = mid+1;
                else
                    h = mid-1;
            }
        }
        return -1;
    }
};


class Solution {
public:
    int findPivot(vector<int> & nums) {
        int l = 0 , h = nums.size()-1;
        while(l < h) {
            int m = (l+h)/2;
            if( m < h && nums[m] > nums[m+1])
                return m;
            else if( l < m && nums[m-1] > nums[m])
                return m-1;
            else if( nums[l] < nums[m] )
                l = m+1;
            else{
                 h = m-1;
            }
        }
        return -1;
    }
    
    int binsrch(vector<int>& nums,int l, int h, int target) {
       int m;
        while(l <= h) {
            m = (l +h)/2;
            if(nums[m] == target)
                return m;
            if(nums[m] > target)
                h = m - 1;
            if(nums[m] < target)
                l = m + 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return -1;
        int pivot =  findPivot(nums);
        if(pivot == -1)
            return binsrch(nums,0,n-1,target);
        else if( nums[pivot] == target) 
            return pivot;
        else if(nums[0] > target)
            return binsrch(nums,pivot+1,n-1,target);
        else
            return binsrch(nums,0,pivot-1,target);
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0)
            return -1;
        if(n==1){
            if(target==nums[0])
                return 0;
            else
                return -1;
        }
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < nums[right]) {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else if (nums[mid] > nums[right]) {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
                right--;
        }
        return -1;
    }
};