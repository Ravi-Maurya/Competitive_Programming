// class Solution {
// public:
//     struct TreeNode{
//         int val;
//         int sum;
//         TreeNode* left;
//         TreeNode* right;
//         TreeNode(int x, int y){
//             val = x;
//             sum = y;
//             left = right = NULL;
//         }
//     };
//     TreeNode* updateBST(TreeNode* root, int idx, int val, int count, vector<int>& res){
//         if(!root){
//             root = new TreeNode(val,1);
//             res[idx] = count;
//             return root;
//         }
//         if(val>root->val){
//             root->right = updateBST(root->right, idx, val, count + root->sum, res);
//         }
//         else{
//             root->sum++;
//             root->left = updateBST(root->left, idx, val, count, res);
//         }
//         return root;
//     }
//     vector<int> countSmaller(vector<int>& nums) {
//         TreeNode* root = NULL;
//         vector<int> res(nums.size());
//         for(int i=nums.size()-1; i>=0 ;i--)
//             updateBST(root,i,nums[i],0,res);
//         return res;
//     }
// };
class Solution {
private:
    int getSum(vector<int>& bit, int idx) {
        int s = 0;
        while (idx) {
            s += bit[idx];
            idx -= idx & -idx;
        }
        return s;
    }
    void update(vector<int>& bit, int n, int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }
    void convert(vector<int>& a) {
        int n = a.size();
        int temp[n];
        for (int i=0; i<n; i++) temp[i] = a[i];
        sort(temp, temp+n);
        for (int i=0; i<n; i++) a[i] = lower_bound(temp, temp+n, a[i]) - temp + 1;
    }
public:
    vector<int> countSmaller(vector<int>& a) {
        int n = a.size();
        vector<int> result(n);
        if (!n) return result;
        vector<int> bit(n+1, 0);
        convert(a);
        for (int i=n-1; i>=0; i--) {
            result[i] = getSum(bit, a[i] - 1);
            update(bit, n, a[i], 1);
        }
        return result;
    }
};