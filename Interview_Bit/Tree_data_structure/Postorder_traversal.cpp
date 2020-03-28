/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> res;
    if(!A)
        return res;
    stack<TreeNode*> postorder;
    do{
        while(A){
            if(A->right)
                postorder.push(A->right);
            postorder.push(A);
            A = A->left;
        }
        A = postorder.top();
        postorder.pop();
        if(A->right && !postorder.empty() && postorder.top()==A->right){
            postorder.pop();
            postorder.push(A);
            A = A->right;
        }
        else{
            res.push_back(A->val);
            A = NULL;
        }
    }while(!postorder.empty());
    return res;
}
