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
    int total = 0;
    int sum(TreeNode* root, int L, int R) {
        std::ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if (root == NULL) {
            return 0;
        }
        if (root->val >= L && root->val <= R) {
            total += root->val;
        }
        return sum(root->left,L,R),sum(root->right,L,R);
        
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        sum(root,L,R);
        return total;
    }
};