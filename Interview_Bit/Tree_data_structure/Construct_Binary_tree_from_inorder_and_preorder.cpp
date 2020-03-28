/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* solve(vector<int> &pre, int l, int r,unordered_map<int,int>& inorder, int& pidx){
    if(l>r)
        return NULL;
    TreeNode* root = new TreeNode(pre[pidx]);
    pidx++;
    if(l==r)
        return root;
    int x = inorder[root->val];
    root->left = solve(pre,l,x-1,inorder,pidx);
    root->right = solve(pre,x+1,r,inorder,pidx);
    return root;
    
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n = A.size();
    unordered_map<int,int> inorder;
    for(int i=0;i<B.size();i++)
        inorder[B[i]] = i;
    int pidx = 0;
    return solve(A,0,n-1,inorder,pidx);
}