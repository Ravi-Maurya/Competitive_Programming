class Solution {
public:
    void nextPermutation(vector<int> &A);
    bool check(vector<int>& a, vector<int>& b){
        for(int i=0; i<a.size();i++)
            if(a[i]!=b[i])
                return false;
        return true;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr = nums;
        vector<vector<int>> res;
        do{
            res.push_back(curr);
            nextPermutation(curr);
        }while(!check(curr,nums));
        return res;
    }
};
void Solution::nextPermutation(vector<int> &A) {
    int n = A.size(),i;
    int invert = n-2;
    while (invert>=0 && A[invert]>=A[invert+1]) invert--;
    if (invert==-1){
        reverse(A.begin(),A.end());
        return;
    }
    for(i = n-1; i>=invert+1; i--){
        if (A[i]>A[invert]){
            swap(A[i],A[invert]);
            break;
        }
    }
    reverse(A.begin()+(invert+1),A.end());
    return;
}
