class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        if(n==0)
            return res;
        int num1 = 0; int count1 = 0;
        int num2 = 0; int count2 = 0;
        for(int i=0; i<n; i++){
            if(num1==nums[i]){
                count1++;
            }
            else if(num2==nums[i]){
                count2++;
            }
            else if(count1==0){
                num1 = nums[i];
                count1++;
            }
            else if(count2==0){
                num2 = nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i]==num1)
                count1++;
            else if(nums[i]==num2)
                count2++;
        }
        if(count1 > n/3)
            res.push_back(num1);
        if(count2 > n/3)
            res.push_back(num2);
        return res;
    }
};