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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while(!q.empty()){
            auto curr1 = q.front();q.pop();
            auto curr2 = q.front();q.pop();
            if(!check(curr1,curr2))
                return false;
            if(curr1 && curr2){
                q.push(curr1->left);
                q.push(curr2->right);
                q.push(curr1->right);
                q.push(curr2->left);
            }
        }
        return true;
    }
};