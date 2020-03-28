/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::kthsmallest(TreeNode* A, int B) {
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
        if(res.size()==B)
            return res[B-1];
        curr = curr->right;
    }
}
