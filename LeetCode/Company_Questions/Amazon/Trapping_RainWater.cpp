class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        if(n<=2)
            return res;
        vector<int> left(n,0), right(n,0);
        left[0] = height[0];
        right[n-1]=  height[n-1];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],height[i]);
            right[n-i-1] = max(right[n-i],height[n-i-1]);
        }
        for(int i=1;i<n-1;i++)
            res += min(left[i],right[i])-height[i];
        return res;
    }
};

class Solution2 {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int res = 0;
        int left_max = 0, right_max = 0;
        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>=left_max)
                    left_max = height[left];
                else
                    res += (left_max-height[left]);
                
                left++;
            }
            else{
                if(height[right]>=right_max)
                    right_max = height[right];
                else
                    res += (right_max-height[right]);
                
                right--;
            }
        }
        return res;
    }
};