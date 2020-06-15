/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* a, TreeNode* b){
        if(!a && !b)
            return true;
        if(!a || !b)
            return false;
        return (a->val == b->val);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(!check(p,q))
            return false;
        queue<TreeNode*> dqp, dqq;
        dqp.push(p);
        dqq.push(q);
        while(!dqp.empty() && !dqq.empty()){
            p = dqp.front();dqp.pop();
            q = dqq.front();dqq.pop();
            if(!check(p,q))
                return false;
            if(p){
                dqp.push(p->left);
                dqp.push(p->right);
            }
            if(q){
                dqq.push(q->left);
                dqq.push(q->right);
            }
        }
        if(dqp.empty() && dqp.empty())
            return true;
        return false;
    }
};