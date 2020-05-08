class Solution {
public:
    int search(vector<int>& nums, int target);
};
int Solution::search(vector<int> &A, int B) {
    int n = A.size();
    int l = 0, h = n-1;
    while(l<=h){
        int mid = (l+h)>>1;
        if (A[mid]==B)
            return mid;
        else if (A[l]<=A[mid]){
            if (A[l]<=B && B<=A[mid])
                h = mid-1;
            else
                l = mid+1;
        }
        else{
            if (A[mid]<=B && B<=A[h])
                l = mid+1;
            else
                h= mid-1;
        }
    }
    return -1;
}
