/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* solve(const vector<int> &A, int l, int r){
    if(l>r || l<0 || r>=A.size())
        return NULL;
    int mid = l - (l-r)/2;
    TreeNode* root = new TreeNode(A[mid]);
    root->left = solve(A,l,mid-1);
    root->right = solve(A,mid+1,r);
    return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return solve(A,0,A.size()-1);
}
