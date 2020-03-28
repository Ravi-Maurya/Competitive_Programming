/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
pair<bool,int> check(TreeNode* root){
    if(!root)
        return make_pair(true,-1);
    pair<bool,int> left = check(root->left);
    if(!left.first)
        return make_pair(false,0);
    pair<bool,int> right = check(root->right);
    if(!right.first)
        return make_pair(false,0);
    bool is_balanced = abs(left.second-right.second)<=1;
    int height = 1+max(left.second,right.second);
    return make_pair(is_balanced,height);
}
int Solution::isBalanced(TreeNode* A) {
    return check(A).first;
}
