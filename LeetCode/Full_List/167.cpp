class Solution {
public:
    vector<int> twoSum(vector<int>& A, int target) {
        int low = 0, high = A.size()-1;
        while(low<high){
            int sum = A[low] + A[high];
            if(sum==target)
                return {low+1,high+1};
            else if(sum<target)
                low++;
            else
                high--;
        }
        return {};
    }
};