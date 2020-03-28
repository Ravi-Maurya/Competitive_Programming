/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::t2Sum(TreeNode* A, int B) {
    stack<TreeNode*> inorder;
    TreeNode* curr = A;
    vector<int> res;
    while(curr || !inorder.empty()){
        while(curr){
            inorder.push(curr);
            curr = curr->left;
        }
        curr = inorder.top();
        inorder.pop();
        res.push_back(curr->val);
        curr = curr->right;
    }
    int l =0, r = res.size()-1;
    while(l<r){
        if(res[l]+res[r] == B)
            return 1;
        else if(res[l]+res[r]<B)
            l++;
        else
            r--;
    }
    return 0;
}
