/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int>> res;
    if(!A)
        return {};
    queue<TreeNode*> q;
    q.push(A);
    q.push(NULL);
    vector<int> tmp;
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(!curr){
            res.emplace_back(tmp);
            tmp.clear();
            if(!q.empty())
                q.push(NULL);
        }
        else{
            tmp.push_back(curr->val);
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }
    return res;
}
