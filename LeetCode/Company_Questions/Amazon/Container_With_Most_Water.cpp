class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), res = 0, i = 0;
        int j = n-1;
        while(i<j){
            res = max(res,min(height[i],height[j])*(j-i));
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return res;
    }
};