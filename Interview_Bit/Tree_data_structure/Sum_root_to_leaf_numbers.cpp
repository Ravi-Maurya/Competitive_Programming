/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define mod 1003
void solve(long long int &res, long long int sm, TreeNode* root){
    if(root==NULL)
        return;
    sm = (sm*10)%mod + (root->val)%mod;
    if(!root->left && !root->right){
        res += sm%mod;
    }
    solve(res,sm,root->left);
    solve(res,sm,root->right);
    free(root->left);
    free(root->right);
    return;
}
int Solution::sumNumbers(TreeNode* A) {
    long long int res = 0;
    solve(res,0,A);
    return res%mod;
}
