class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        int j = 0;
        while(j<n && A[j]<0)
            j++;
        int i = j-1;
        vector<int> res(n);
        int t = 0;
        while(i>=0 && j<n){
            if(A[i]*A[i] < A[j]*A[j]){
                res[t++] = A[i]*A[i];
                i--;
            }
            else{
                res[t++] = A[j]*A[j];
                j++;
            }
        }
        while(i>=0){
            res[t++] = A[i]*A[i];
            i--;
        }
        while(j<n){
            res[t++] = A[j]*A[j];
            j++;
        }
        return res;
    }
};