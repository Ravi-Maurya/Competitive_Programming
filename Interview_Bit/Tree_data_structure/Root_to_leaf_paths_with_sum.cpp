/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* A, int B,int sm, vector<vector<int>> &res, vector<int>& tmp){
    if(!A)
        return;
    tmp.push_back(A->val);
    sm+=A->val;
    if(B==sm && A->left == NULL && A->right==NULL)
        res.push_back(tmp);
    if(A->left!=NULL){
        solve(A->left, B,sm, res, tmp);
        free(A->left);
    }
    if(A->right!=NULL){
        solve(A->right, B,sm, res, tmp);
        free(A->right);
    }
    tmp.pop_back();
    return;
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> res;
    vector<int> tmp;
    solve(A,B,0,res,tmp);
    return res;
    
}
