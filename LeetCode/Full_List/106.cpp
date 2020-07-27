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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0)
            return NULL;
        TreeNode* curr;
        TreeNode* root;
        stack<TreeNode*> res;
        root = new TreeNode(postorder.back());
        res.push(root);
        postorder.pop_back();
        while(true){
            if(inorder.back() == res.top()->val){
                curr = res.top();
                res.pop();
                inorder.pop_back();
                if(inorder.size()==0)
                    break;
                if(!res.empty() && inorder.back() == res.top()->val)
                    continue;
                curr->left = new TreeNode(postorder.back());
                postorder.pop_back();
                res.push(curr->left);
            }
            else{
                curr = new TreeNode(postorder.back());
                postorder.pop_back();
                res.top()->right = curr;
                res.push(curr);
            }
        }
        return root;
    }
};