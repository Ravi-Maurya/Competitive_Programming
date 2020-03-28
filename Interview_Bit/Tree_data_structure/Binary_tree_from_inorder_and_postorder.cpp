/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* solve(unordered_map<int,int>& inorder,const vector<int>& postorder, int l, int r, int &pidx){
    if(l>r)
        return NULL;
    TreeNode* root = new TreeNode(postorder[pidx]);
    pidx--;
    if(l==r)
        return root;
    int x = inorder[root->val];
    root->right = solve(inorder, postorder, x+1, r, pidx);
    root->left = solve(inorder, postorder, l, x-1, pidx);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n = B.size();
    unordered_map<int,int> inorder;
    for(int i=0;i<A.size();i++)
        inorder[A[i]] = i;
    int pidx = n-1;
    return solve(inorder, B, 0, n-1, pidx);
}
