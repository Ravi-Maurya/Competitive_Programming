class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        int m = nums1.size();
        int n = nums2.size();
        if(m==0 || n==0){
            vector<int> tmp = (m==0)?nums2:nums1;
            int k = tmp.size();
            if(k&1){
                return (tmp[(k-1)/2])*1.0;
            }
            else{
                return (tmp[k/2] + tmp[k/2  - 1])*0.5;
            }
        }
        int l = 0, h = m, mid = (m+n+1)/2, max1,max2,min1,min2;
        bool flag = ((m+n)&1);
        double res;
        while(l<=h){
            int mid1 = (l+h)/2;
            int mid2 = mid - mid1;
            max1 = (mid1==0)?INT_MIN:nums1[mid1-1];
            min1 = (mid1==m)?INT_MAX:nums1[mid1];
            
            max2 = (mid2==0)?INT_MIN:nums2[mid2-1];
            min2 = (mid2==n)?INT_MAX:nums2[mid2];
            
            if(max1<=min2 && max2<=min1){
                if(!flag){
                    res = (max(max1,max2) + min(min1,min2))/2.0;
                }
                else
                    res = max(max1,max2);
                return res;
            }
            else if(max1>min2)
                h = mid1-1;
            else
                l = mid1+1;
        }
        return 0.0;
    }
};