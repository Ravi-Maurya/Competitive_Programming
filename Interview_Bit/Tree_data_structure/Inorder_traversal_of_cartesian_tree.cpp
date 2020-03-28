/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int maxidx(vector<int> &A, int l, int r ){
    if(l<0 || r>=A.size())
        return -1;
    if(l==r)
        return l;
    int idx = -1, mx = INT_MIN;
    for(int i=l;i<=r;i++)
        if(mx<A[i]){
            mx = A[i];
            idx = i;
        }
    return idx;
}

TreeNode* solve(vector<int> &A, int l, int r){
    int idx = maxidx(A,l,r);
    if(idx==-1)
        return NULL;
    TreeNode* root = new TreeNode(A[idx]);
    root->left = solve(A,l,idx-1);
    root->right = solve(A,idx+1,r);
    return root;
}

TreeNode* Solution::buildTree(vector<int> &A) {
    int n = A.size();
    return solve(A,0,n-1);
}
