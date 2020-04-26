/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int res = 0;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            auto curr = s.top();
            s.pop();
            if(curr){
                if(L<= curr->val && curr->val <=R)
                    res += curr->val;
                if(L<curr->val)
                    s.push(curr->left);
                if(curr->val<R)
                    s.push(curr->right);
            }
        }
        return res;
    }
};