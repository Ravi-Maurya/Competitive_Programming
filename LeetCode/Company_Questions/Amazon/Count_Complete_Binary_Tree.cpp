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
    int countNodes(TreeNode* root) {
        int res = 0;
        if(!root){
            return res;
        }
        queue<TreeNode*> queue;
        queue.push(root);
        res++;
        while(!queue.empty()){
            auto tmp = queue.front();queue.pop();
            if(tmp->left){
                res++;
                queue.push(tmp->left);
            }else{
                return res;
            }
            if(tmp->right){
                res++;
                queue.push(tmp->right);
            }
        }
        return res;
    }
};