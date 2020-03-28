/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> res;
    if(!A)
        return res;
    deque<TreeNode*> dq;
    int l2r = 1;
    dq.push_back(A);
    dq.push_back(NULL);
    vector<int> tmp;
    while(!dq.empty()){
        if(l2r){
            TreeNode* curr = dq.front();
            dq.pop_front();
            if(curr==NULL){
                l2r ^=1;
                res.push_back(tmp);
                tmp.clear();
                if(!dq.empty())
                    dq.push_front(NULL);
            }
            else{
                if(curr->left)
                    dq.push_back(curr->left);
                if(curr->right)
                    dq.push_back(curr->right);
                tmp.push_back(curr->val);
            }
        }
        else{
            TreeNode* curr = dq.back();
            dq.pop_back();
            if(curr==NULL){
                l2r ^=1;
                res.push_back(tmp);
                tmp.clear();
                if(!dq.empty())
                    dq.push_back(NULL);
            }
            else{
                if(curr->right)
                    dq.push_front(curr->right);
                if(curr->left)
                    dq.push_front(curr->left);
                tmp.push_back(curr->val);
            }
        }
    }
    return res;
    
}
