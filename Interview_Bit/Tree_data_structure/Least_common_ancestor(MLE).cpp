/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// MLE
pair<int,int> LCA(TreeNode* root, int val1, int val2){
    if(!root)
        return make_pair(0,-1);
    pair<int,int> left = LCA(root->left,val1,val2);
    if(left.first==2)
        return left;
    pair<int,int> right = LCA(root->right,val1,val2);
    if(right.first==2)
        return right;
    int number_of_nodes = left.first + right.first + (int)(root->val==val1) + (int)(root->val==val2);
    return make_pair(number_of_nodes, number_of_nodes==2 ? root->val: -1);
}
int Solution::lca(TreeNode* A, int B, int C) {
    return LCA(A,B,C).second;
}