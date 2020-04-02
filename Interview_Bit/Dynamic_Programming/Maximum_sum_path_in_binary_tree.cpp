/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int solve(TreeNode* root, int& res){
    if (!root)
        return 0;
    int val = root->val;
    int left = solve(root->left,res);
    int right = solve(root->right,res);
    int x = max(max(left,right)+val,val);
    int y = max(x,left+right+val);
    res = max(res,y);
    return x;
    
}
int Solution::maxPathSum(TreeNode* A) {
    int res = INT_MIN;
    solve(A,res);
    return res;
}
