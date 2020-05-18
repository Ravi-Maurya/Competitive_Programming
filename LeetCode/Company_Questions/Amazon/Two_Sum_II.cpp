class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size()-1;
        while(i<j){
            int curr_sum = numbers[i]+numbers[j];
            if(curr_sum==target)
                return {i+1,j+1};
            else if(curr_sum<target)
                i++;
            else
                j--;
        }
        return {};
    }
};