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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(p && q)
            return ((p->val == q->val) && (isSameTree(p->left,q->left)) && (isSameTree(p->right,q->right)));
        return false;
    }
    bool trav(TreeNode* s, TreeNode* t){
        return (s!=NULL && (isSameTree(s,t) || trav(s->left,t) || trav(s->right,t)));
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return trav(s,t);
    }
};