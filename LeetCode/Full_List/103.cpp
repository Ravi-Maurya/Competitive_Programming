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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*> traverse;
        int dir = 1;
        vector<vector<int>> res;
        if(!root)
            return res;
        traverse.push_back(root);
        while(!traverse.empty()){
            int size = traverse.size();
            vector<int> tmp;
            while(size--){
                if(dir){
                    auto curr = traverse.front();
                    traverse.pop_front();
                    tmp.push_back(curr->val);
                    if(curr->left)
                        traverse.push_back(curr->left);
                    if(curr->right)
                        traverse.push_back(curr->right);
                }
                else{
                    auto curr = traverse.back();
                    traverse.pop_back();
                    tmp.push_back(curr->val);
                    if(curr->right)
                        traverse.push_front(curr->right);
                    if(curr->left)
                        traverse.push_front(curr->left);
                }
            }
            if(tmp.size())
                res.push_back(tmp);
            dir ^= 1;
        }
        return res;
    }
};