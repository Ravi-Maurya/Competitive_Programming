class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        if(m>n){
            swap(A,B);
            swap(m,n);
        }
        int low = 0, high = m, k = (m+n+1)/2;
        while(low<=high){
            int i = (low+high)/2;
            int j = k - i;
            if(i<high && B[j-1]>A[i])
                low = i+1;
            else if(i>low && A[i-1]>B[j])
                high = i-1;
            else{
                int max_left = 0;
                if(i==0)
                    max_left = B[j-1];
                else if(j==0)
                    max_left = A[i-1];
                else
                    max_left = max(A[i-1],B[j-1]);
                
                if((m+n)%2==1)
                    return max_left;
                int min_right = 0;
                if(i==m)
                    min_right = B[j];
                else if(j==n)
                    min_right = A[i];
                else
                    min_right = min(A[i],B[j]);
                return (min_right+max_left)/2.0;
            }
        }
        return 0.0;
    }
};