/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
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
    return res;
}
